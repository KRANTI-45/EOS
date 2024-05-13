/* 1. From one parent create 5 child processes. Each child should run for 5 seconds and print count along with its pid. Parent should wait for all child processes
to complete and clean all of them. Hint: use loop to fork() multiple child processes.*/

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main ()
{

int ret,i,s;
for(i=1;i<6;i++){
    ret =fork();
    sleep(1);
	if (ret==0){
	   printf("child:%d\n",i);
	   printf("child pid:%d\n",getpid());
	   _exit(0);
	}
}

for (i=1;i<6;i++){
    printf("parent :%d\n",i);
	sleep(1);
     //waitpid(-1,&s,0);
    printf("parent pid:%d\n",getpid());
	printf("child exit:%d\n",WEXITSTATUS(s));
	}
	return 0;
	}

