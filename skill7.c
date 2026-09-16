#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        printf("Fork failed.\n");
        return 1;
    }

    if (pid == 0) {
        printf("Child Process Started\n");
        printf("Child PID: %d\n", getpid());

        sleep(3);

        printf("Child Process Finished\n");
        exit(25);
    }
    else {
        printf("Parent PID: %d\n", getpid());
        printf("Waiting for Child Process...\n");

        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child exited normally.\n");
            printf("Exit Status: %d\n", WEXITSTATUS(status));
        }
        else {
            printf("Child did not exit normally.\n");
        }
    }

    return 0;
}
