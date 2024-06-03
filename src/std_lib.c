#include "../include/std_lib.h"

int div(int a,int b){
    if(b==0) return -1;
    else return a/b;
}

int mod(int a,int b){
    if(a<0 || b<0) return -1;
    else return a%b;
}

void memcpy(byte* src, byte* dst, unsigned int size){
    int i;
    for(i=0;i<size;i++) dst[i] = src[i];
}

unsigned int strlen(char* str){
    unsigned int size = 0;
    while(*str!='\0'){
        str++;
        size++;
    }
    return size;
}

bool strcmp(char* str1, char* str2){
    if(strlen(str1)!=strlen(str2)) return false;
    else{
        int i;
        for(i=0;i<strlen(str1);i++){
            if(str1[i]!=str2[i]) return false;
        }
        return true;
    }
}
void strcpy(char* src, char* dst){
     while (*src != '\0') {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = '\0';
}
void clear(byte* buf, unsigned int size){
    int i;
    for (i = 0; i < size; ++i) {
        buf[i] = 0;
    }
}
