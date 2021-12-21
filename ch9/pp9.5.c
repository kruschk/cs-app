#include <stdlib.h>
#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

void mmapcopy(char const *const pathname) {
    int fd; //, errsv; // TODO
    struct stat status;
    void *p;

    fd = open(pathname, O_RDONLY);
    if (-1 == fd) {
        perror("mmapcopy");
        exit(1);
    }
    if (-1 == fstat(fd, &status)) {
        perror("mmapcopy");
        exit(2);
    }
    p = mmap(NULL, status.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (MAP_FAILED == p) {
        perror("mmapcopy");
        exit(3);
    }
    printf("%s", (char *)p);
    if (-1 == munmap(p, status.st_size)) {
        perror("mmapcopy");
        exit(4);
    }
    if (-1 == close(fd)) {
        perror("mmapcopy");
        exit(5);
    }
}

int main(const int argc, const char *const *const argv) {
    if (2 != argc) {
        fprintf(stderr, "usage: %s file", argv[0]);
        exit(1);
    }
    mmapcopy(argv[1]);
    return 0;
}
