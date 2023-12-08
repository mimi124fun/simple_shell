#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/wait.h>

void executeCommand(const char *command) {
    pid_t pid;
    int status;


    char *args[10]; 
    int argCount = 0;

    char *token = strtok(command, " ");
    while (token != NULL && argCount < 10) {
        args[argCount++] = token;
        token = strtok(NULL, " ");
    }
  args[argCount] = NULL; 

  
    if (strcmp(args[0], "exit") == 0) {
     
        exit(EXIT_SUCCESS);
    }
    args[argCount] = NULL; 
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
      
        if (execvp(args[0], args) == -1) {
            
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    } else {
       
        waitpid(pid, &status, 0);

        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
            fprintf(stderr, "./shell: %s: command not found\n", args[0]);
        }
    }
}
