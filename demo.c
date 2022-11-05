#include "stdlib.h"
#include "stdio.h"
#include "stdbool.h"
#define maxSize 10

typedef char Type;

typedef struct{
    Type *data;
    int length;
}String;

void init(String *str){
    str->length = 0;
}

int length(char *c){
    int x=0;
    while(*c++){
        x++;
    }
    return x;
}

String translate(char *c){
    String str;
    init(&str);
    int x=length(c);
    str.data = c;
    str.length = x;
    return str;
}

void main(){
    String str = translate("abcc");
    printf("%s",str.data);
}