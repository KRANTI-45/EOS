//2. Improve your shell program so that it should not be terminated due to SIGINT (ctrl+C).


#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void sigint_handler(int sig) {
	printf("SIGINT caught: %d\n", sig);
}
int main ()
{
//int i=1;
signal(SIGINT, sigint_handler);
  char cmd[512],*ptr,*args[32];
  int i,ret,err,s;
  while(1){
     printf("cmd> ");
	 gets(cmd);
	 i=0;
	 ptr=strtok(cmd, "  ");
	 args[i] = ptr;
	 i++;
	 do{
	 ptr=strtok(NULL, " ");
	 args[i]=ptr;
	 i++;
	 } while(ptr !=NULL);


      
	    if(strcmp(args[0], "exit") == 0)
			break;	// internal command 1 -- exit
		else if(strcmp(args[0], "cd") == 0)
			chdir(args[1]);	// internal command 2 -- cd chdir(args[1]);
         else {

		       ret=fork();
			   if (ret ==0){
			        err=execvp(args[0],args);
					if(err < 0)
					{
					    perror("bad commnd");
					}
			}
			else 
			    wait(&s);
	
	}		

	} 
// signal(SIGINT, sigint_handler);
 printf("...\n");

return 0;
}

