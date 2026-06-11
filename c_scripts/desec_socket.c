#include<stdio.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(){
    int meusocket;
    int conecta;

    struct sockaddr_in alvo;

    meusocket = socket(AF_INET, SOCK_STREAM,0);
    alvo.sin_family = AF_INET;
    alvo.sin_port = htons(80);
    alvo.sin_addr.s_addr = inet_addr("186.217.0.51");

    conecta = connect(meusocket, (struct sockaddr *)&alvo, sizeof alvo);
    if(conecta == 0){
        printf("Porta aberta!\n");
        close(meusocket);
        close(conecta);
    }
    else{
        printf("Porta Fechada!\n");
    }
}