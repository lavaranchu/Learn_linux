#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    setenv("MY_COMMAND", "ls", 1);

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } 
    else if (pid == 0) {
        char *cmd = getenv("MY_COMMAND");
        if (cmd == NULL) {
            printf("[Child] MY_COMMAND not found!\n");
            exit(1);
        }

        printf("[Child] Executing command: %s\n", cmd);
        execlp(cmd, cmd, "-l", NULL); 
        perror("execlp failed");
        exit(1);
    } 
    else {
        wait(NULL);
        printf("[Parent] Done.\n");
    }

    return 0;
}
