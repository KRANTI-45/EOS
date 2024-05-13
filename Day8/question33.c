// 3. Find max number of child processes that can be created on Linux using C program? Hint: use fork() in inﬁnite loop (wisely).
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main (){
int ret,s,i,j;
 i=1;
while (1) {
     ret=fork();
	 if(ret ==0){
	 printf("kranti");
	 _exit(0);
	}
	else if( ret== -1)
	   break;
	else {
	  i++;
	  printf("child count : %d\n",i);
	  }
}

for (i=1;j<=i;j++)
     wait(&s);

}	 

