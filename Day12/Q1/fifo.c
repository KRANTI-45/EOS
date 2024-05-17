#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main ()
{
     int fd,fd1,cnt,r;
	 //int arr[2],arr1[2];
	 int num1,num2;
	 fd = open("/home/sunbeam/fifo/desd_fifo",O_WRONLY);
	 if (fd<0) {
	     perror ("oprn () failed");
		 _exit(1);
		 
		}
	printf("enter a two numbers:  ");
	scanf("%d %d",&num1,&num2);
	cnt=write(fd,&num1,sizeof(num1));
	cnt=write(fd,&num2,sizeof(num2));
	fd1=open("/home/sunbeam/fifo/desd_fifo1",O_RDONLY);
	if (fd1<0) {
	     perror ("oprn () failed");
		 _exit(1);
		 
		}
	read(fd,&r,sizeof(r));
	cnt = read(fd1, &r, sizeof(r));
	printf("result:%d\n",r);
	close(fd);
	close(fd1);
	return 0;
	}
