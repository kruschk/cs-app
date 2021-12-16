#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <signal.h>
#include <unistd.h>

void unix_error(char *msg) /* Unix-style error */
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
}

unsigned int wakeup(unsigned int seconds) {
    unsigned int remaining = sleep(seconds);
    printf("Woke up at %u s.\n", seconds - remaining);
    return remaining;
}

void handler(int signal) {}

int main(const int argc, const char *const *const argv) {
    unsigned long int seconds;

    if (2 != argc) {
        fprintf(stderr, "usage: %s <seconds>\n", argv[0]);
        exit(1);
    }

    if (SIG_ERR == signal(SIGINT, handler)) {
        unix_error("signal error");
    }
    seconds = strtoul(argv[1], NULL, 10);
    wakeup(seconds);
}
