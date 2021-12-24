#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char **argv) {
    struct addrinfo *p, *listp, hints;
    char buf[INET_ADDRSTRLEN];
    int rc;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <domain name>\n", argv[0]);
        exit(0);
    }

    /* Get a list of addrinfo records */
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET; /* IPv4 only */
    hints.ai_socktype = SOCK_STREAM; /* Connections only */
    if ((rc = getaddrinfo(argv[1], NULL, &hints, &listp)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(rc));
        exit(1);
    }

    /* Walk the list and display each IP address */
    for (p = listp; p; p = p->ai_next) {
        inet_ntop(AF_INET,
                  &((struct sockaddr_in *)p->ai_addr)->sin_addr,
                  buf,
                  INET_ADDRSTRLEN);
        printf("%s\n", buf);
    }

    /* Clean up */
    freeaddrinfo(listp);
    exit(0);
}
