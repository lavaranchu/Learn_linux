#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        printf("[Child] PID = %d, PPID = %d\n", getpid(), getppid());
        exit(10);
    } 
    else {
        printf("[Parent] PID = %d, Child PID = %d\n", getpid(), pid);
        wait(&status);

        if (WIFEXITED(status)) {
            printf("[Parent] Child exited normally with status = %d\n",
                   WEXITSTATUS(status));
        } else {
            printf("[Parent] Child terminated abnormally\n");
        }
    }
    return 0;
}
