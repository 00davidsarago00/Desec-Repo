#include<stdio.h>
#include<netdb.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define DST_PORT 21
#define SA struct sockaddr *

int main(int argc, char *argv[]){
    
    if(argc<2){
        printf("Uso: %s <host>", argv[0]);
        return 0;
    }

    int mysocket;
    int connection;

    struct sockaddr_in target;

    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);
    target.sin_port = htons(DST_PORT);

    while(1){
        mysocket = socket(AF_INET, SOCK_STREAM, 0);
        connection = connect(mysocket, (SA)&target, sizeof target);
        printf("conexao! [ ;) ]");
    }

    return 0;
}