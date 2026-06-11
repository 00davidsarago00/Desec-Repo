#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>


//The hostent structure is defined in <netdb.h> as follows:

//        struct hostent {
//            char  *h_name;            /* official name of host */
//            char **h_aliases;         /* alias list */
//            int    h_addrtype;        /* host address type */
//            int    h_length;          /* length of address */
//            char **h_addr_list;       /* list of addresses */
//        }

//        #define h_addr h_addr_list[0] /* for backward compatibility */

int main(int argc, char *argv[]){
    
    if (argc < 2){
        printf("Sem argumentos suficientes");
        return 0;
    }
    
    else{
    struct hostent *alvo = gethostbyname(argv[1]);
    
    if (alvo == NULL){
        herror("gethostbyname");
        return 1;
    }
    printf(" Nome: %s\n", alvo->h_name);

    for(int i=0; alvo->h_addr_list[i] != NULL; i++){
        struct in_addr addr;
        addr = *(struct in_addr *) alvo->h_addr_list[i];
        printf("IP[%d]: %s\n", i, inet_ntoa(addr));
    }
    return 0;
}
}

