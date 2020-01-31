#include<stdio.h>
#include<stdlib.h>

char* itoa(int x, char* str, int base){
    char* chs="0123456789abcdefghijklmnopkrstuvwxyz";
    int i=0;
    char* p= str;
    char* q = str;
    char tmp;

    if (base > 36)
        return NULL;

    if (x < 0){
        *p++ = '-';
        q++; 
        x = -x;
    }
        
    do {
        *p++ = chs[x%base]; 
        x = x/base;
    }while(x != 0);

    *p = '\0';
    p--;

    // reverse through swap
    while(q < p){
        tmp = *q;
        *q = *p;
        *p = tmp;     
        q++;
        p--;
    }
    return str;
}

int main(){
    int i=-42;
    char str[100];
    printf("%s\n", itoa(i, str, 16));

}
