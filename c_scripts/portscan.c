#include<stdio.h>
#include<netdb.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define SA struct sockaddr * 

int main(int argc, char *argv[]){
    
    if(argc < 2){
        printf("Utilizacao: %s <host>", argv[0]);
        return 0;
    }
    
    printf("Verificando IP: %s\n", argv[1]);
    
    int mysocket;
    int connection; 

    struct sockaddr_in target;

    
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);
    
    for(int i = 1; i<65535; i++){
        mysocket = socket(AF_INET, SOCK_STREAM, 0);
        target.sin_port = htons(i);
        connection = connect(mysocket, (SA)&target, sizeof target);
        if (connection == 0){
            printf("PORTA ABERTA! SOCKET -> %s:%d\n", argv[1], i);
        }
        else{
            //printf("PORTA FECHADA! SOCKET -> %s:%d", argv[1], i);
        }
        close(mysocket);
    }

    
    return 0;
}