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
