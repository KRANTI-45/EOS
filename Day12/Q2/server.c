#include<stdio.h>
#include<string.h>
#include<sys/un.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<arpa/inet.h>

#define SOCKET_PATH "/home/user/Desktop/ClassWork/EOS_Assignments/Day12_Q2/desd_socket"

int main(){

int serv_fd, ret, n1, n2;
int res, cli_fd, cli_addr;
socklen_t socklen;
char sun_path[108];

struct sockaddr_un serv_addr;
// ...
serv_fd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(serv_fd < 0) {
		perror("socket() failed");
		_exit(1);
	}

serv_addr.sun_family = AF_UNIX;
//serv_addr.sun_path = "/home/user/Desktop/ClassWork/EOS_Assignments/Day12_Q2/desd_socket";
strcpy(serv_addr.sun_path, SOCKET_PATH);

ret = bind(serv_fd, (struct sockaddr*) &serv_addr, sizeof(serv_addr));
if(ret < 0) {
		perror("bind() failed");
		_exit(2);
	}

	listen(serv_fd, 5);

	socklen = sizeof(cli_addr);

while(1) {
cli_fd = accept(serv_fd, (struct sockaddr*)&cli_addr, &socklen);
if(cli_fd < 0){
      perror("accept() failed");
	  _exit(3);
}

read(cli_fd, &n1, sizeof(n1));
read(cli_fd, &n2, sizeof(n2));
printf("......Numbers received......\n");

res = n1 + n2;
write(cli_fd, &res, sizeof(res));
close(cli_fd);
}

//close(cli_fd);
shutdown(serv_fd, SHUT_RDWR);


return 0;
}
