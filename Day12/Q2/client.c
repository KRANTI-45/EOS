#include<arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/un.h>

#define SOCKET_PATH "/home/user/Desktop/ClassWork/EOS_Assignments/Day12_Q2/desd_socket"

// client

int main(){

int cli_fd, ret, n1, n2;
int res;

struct sockaddr_un serv_addr;

cli_fd = socket(AF_UNIX, SOCK_STREAM, 0);
if(cli_fd < 0){
       perror("socket() failed");
	   _exit(1);
}

serv_addr.sun_family = AF_UNIX;
//serv_addr.sun_path = "/home/user/Desktop/ClassWork/EOS_Assignments/Day12_Q2/desd_socket";
strcpy(serv_addr.sun_path, SOCKET_PATH);

ret = connect(cli_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
if(ret < 0) {
		perror("connect() failed");
		_exit(2);
	}

printf("client: \n");
printf("Enter two no.s: \n");
scanf("%d %d",&n1, &n2);

write(cli_fd, &n1, sizeof(n1));
write(cli_fd, &n2, sizeof(n2));

read(cli_fd, &res, sizeof(res));
printf("Addition: %d \n",res);

return 0;
}
