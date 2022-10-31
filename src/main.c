#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/net.h"
#include "../include/defs.h"

typedef struct Args{
    char* name;
    char host;
    char* to_ip;
    char* from_ip;
} Args;

struct Args begin();

int main(){
    Args args = begin();
    printf("%s", args.name);
    return 0;
}

struct Args begin(){
    char name[12];
    char host = 'n';
    char *to_ip;
    char *from_ip;

    printf("Welcome to TChat");
    printf("/////////////////");
    printf("enter your name: ");
    scanf("%s", name);
    printf("/////////////////");
    printf("do you want to host the chat? y on n");
    scanf("%s", &host);

    if(host != 'y'){
        host = 'n';
    }
    else{
        host = 'y';
    }

    if(host == 'y'){
        char *ip = hostServer();
        to_ip = malloc(sizeof(to_ip));
        strcpy(to_ip, "");
        from_ip = malloc(sizeof(from_ip));
        strcpy(from_ip, "");
    }
    
    Args args = {name, host, to_ip, from_ip};

    free(from_ip);
    free(to_ip);

    return args;
}