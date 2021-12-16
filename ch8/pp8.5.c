#include <stdio.h>
#include <unistd.h>

unsigned int wakeup(unsigned int seconds) {
    unsigned int remaining = sleep(seconds);
    printf("Woke up at %u s.\n", seconds - remaining);
    return remaining;
}

int main(void) {
    wakeup(5);
}
