void executeCommand(const char *command) {
    pid_t pid;

 
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        
        if (execlp(command, command, NULL) == -1) {
            
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    } else {
        
        waitpid(pid, NULL, 0);
        if (WIFEXITED(status) && WEXITSTATUS(status) != 0) {
           
            fprintf(stderr, "./shell: %s: command not found\n", command);
        }
    }
}

