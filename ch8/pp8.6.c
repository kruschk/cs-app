#include <stdio.h>

int
main(const int argc,
     const char *const *const argv,
     const char *const *const envp)
{
    printf("Command-line arguments:\n");
    for (int i = 0; i < argc; i++) {
        printf("\targv[%d]: %s\n", i, argv[i]);
    }
    printf("Environment variables:\n");
    for (unsigned i = 0; NULL != envp[i]; i++) {
        printf("\tenvp[%d]: %s\n", i, envp[i]);
    }
}
