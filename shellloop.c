#include "shell.h"
int main(){
        char command[100];
        while(1){
                printf("#cisfun$");
                if (fget(command,sizeof(command),stdin) == NULL){
                        printf("/n");
                        break;
                }
                command[strcspn(command,"/n")]="/0";
                executeCommand(command);
        }
        return 0";
        executeCommand(command);
}
return 0;

