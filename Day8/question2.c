/* 2. From a parent process (A) create a child process (B). The child (B) in turn creates new child process (C) and it (C) in turn create new child (D). All these
processes should run concurrently for 5 seconds and cleaned up properly upon termination. */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

int main(){
int A,B,C,D,s1,s2,s3,s4,i;
for(i=1;i<5;i++){
    //ret =fork();
    sleep(1);
 A=fork();
 if(A==0){
    B=fork();
	if(B==0){
	   C=fork();
	   if(C==0){
	     D=fork();
		 if(D==0){
		  printf("kranti");
		  _exit(0);
		  }
          printf("child D:%d\n",D);
		  printf("child D count:%d\n",i);
		  waitpid(D,&s4,0);
		  exit(0);
		  }
		  printf("child C :%d\n",C);
		  printf("child C count:%d\n",i);
		 waitpid(C,&s3 ,0);
		 exit(0);
		 }
		 printf("child B:%d\n",B);
		 printf("child B count:%d\n",i);
		waitpid(B,&s2,0);
	    exit(0);
	}
	}
for (i=1;i<10;i++){
     printf("parent :%d\n",i);
     sleep(1);
	
printf("paraent A:%d\n",A);
waitpid(A,&s1,0);	
	  }
}
