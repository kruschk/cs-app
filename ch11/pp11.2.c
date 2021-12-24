// hex2dd.c
//
// It's not at all clear from the problem statement or the sample output, but
// based on the solution, what I believe is intended is a program that accepts
// a big-endian unsigned hexadecimal integer and returns a network byte order
// dotted-decimal string. Since the problem statement is unclear, and the
// book's solution doesn't implement what the problem asks for, I've
// implemented some Frankensteinian hybrid of what was requested and what the
// "solution" was.

#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#include <arpa/inet.h>

int main(int argc, char **argv) {
    char *end_pointer;
    uint16_t input;
    struct in_addr input_addr;
    char output[INET_ADDRSTRLEN];

    if (argc != 2) {
        fprintf(stderr, "usage: %s value\n", argv[0]);
        exit(1);
    }

    // Parse the big-endian unsigned hexadecimal integer from the command line,
    // storing it in the machine's native endianness.
    errno = 0;
    // The implicit cast from unsigned long to uint16_t here truncates the
    // higher-order bits of the input, which leads to some unexpected results.
    input = strtoul(argv[1], &end_pointer, 0);
    if (0 != errno) {
        perror("strtoul");
        exit(2);
    } else if (argv[1] == end_pointer || '\0' != *end_pointer) {
        // Pointer not advanced
        fprintf(stderr,
                "%s: invalid input\n",
                argv[0]);
        exit(3);
    }

    // Convert the input address to dotted-decimal. The last two fields of the
    // dotted-decimal representation will always be 0, because it is implicitly
    // zero-extending a uint16_t to a uint32_t.
    input_addr.s_addr = htons(input);
    if (NULL == inet_ntop(AF_INET, &input_addr, output, INET_ADDRSTRLEN)) {
        perror("inet_ntop");
        exit(4);
    }
    printf("%s\n", output);
    return 0;
}
