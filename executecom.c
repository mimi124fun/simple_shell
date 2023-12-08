void executecom(const char*command){
       pid_t pid;
       pid = fork();
    if (pid < 0){
     perror("fork");
      exist(EXIT_FAILURE);
    }else if (pid ==0){
	if (execlp(command,command,NULL)==-1){
	    PERROR("execlp");
	    exit(EXIT_FAILURE);
	}
    }else {
    waitpid(pid,NULL,0);
    }
}
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
