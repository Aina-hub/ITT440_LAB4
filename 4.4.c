#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc,char *argv[])
{

int socket_desc;
struct sockaddr_in server;
char *message,server_reply[6000];

//create socket
socket_desc = socket(AF_INET,SOCK_STREAM,0);
if(socket_desc == -1)
{
printf("Tiada Kawan!");
}

server.sin_addr.s_addr = inet_addr("192.168.56.102");
server.sin_family = AF_INET;
server.sin_port = htons(8888);

//connect to remote server
if(connect(socket_desc,(struct sockaddr*)&server,sizeof(server))<0)
{
puts("Gagal bertemu :(");
return 1;
}

puts("Boleh saja. Ayuh kita berkawan:) \n");

//send some data
message = "Boleh berkenalan juga?";
if(send(socket_desc, message, strlen(message),0)<0)
{
puts("Gagal Berkawan");
return 1;
}

//receive a reply from the server
if(recv(socket_desc,server_reply,2000,0)<0)
{
puts("Gagal Berkenalan");
}
puts("Ayuh bermain bersama :)\n");
puts(server_reply);
return 0;
}
