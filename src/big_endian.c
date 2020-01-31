#include<stdio.h>
#include<stdlib.h>

int isBigEndian(){
    int v = 0x12345678;
    char* p = (char*)&v;
    printf("%x,addr:%x\n", *p, p);
    printf("%x,addr:%x\n", *(p+1), p+1);
    printf("%x,addr:%x\n", *(p+2), p+2);
    printf("%x,addr:%x\n", *(p+3), p+3);
    if (*p == 0x12)
        return 1;
    else
        return 0;
}
int main(){
    printf("%d\n", isBigEndian());
}
