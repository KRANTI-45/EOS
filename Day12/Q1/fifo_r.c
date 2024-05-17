#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>


int main()
{


int fd1,cnt,fd;
int num1,num2,r;
fd=open("/home/sunbeam/fifo/desd_fifo",O_RDONLY);
if(fd<=0){
  perror("open() failed");
  _exit(1);
  }

  printf("waiting for data ...\n");
  cnt=read(fd,&num1,sizeof(num1));
  cnt=read(fd,&num2,sizeof(num2));
  printf("number recevied\n");
  r=num1+num2;
  
  fd1 = open("/home/sunbeam/fifo/desd_fifo1", O_WRONLY);
	if(fd1 < 0) {
		perror("open() failed");
		_exit(1);
	}

cnt = write(fd1, &r, sizeof(r));



close(fd);
close(fd1);
  return 0;
  }


