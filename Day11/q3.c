//3.Find the size of pipe buﬀer in your system.
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>


int main() {
	int i=1,ret1,arr[2];
	char ch='a';
	ret1=pipe(arr);
	int count=0;

	while(1) {
		write(arr[1],&ch,1);
		count ++;
		printf("bytes written :%d\n",count);
		}
	return 0;
}
