#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        for (int i = 0; i < 5; i++) {
            printf("[Child] PID = %d, PPID = %d\n", getpid(), getppid());
            sleep(2);
        }
        printf("[Child] Exiting.\n");
    } 
    else {
        printf("[Parent] PID = %d exiting immediately.\n", getpid());
        exit(0); 
    }
    return 0;
}
