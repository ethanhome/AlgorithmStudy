#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int isHuiWenChuan(char* str) {
    int len = strlen(str);
    int i;
    for(i=0; i<len/2; i++){
        if(str[i] != str[len-i-1]) 
            return 0;
    }
    return 1;
}

int main() {
    int i=0;
    int a[3];
    //for(;i<=3; i++){
    for(;i<3; i++){
        a[i] = 0;
        printf("i=%d\n", i); 
    }
    printf("hello, world!\n");
    printf("%d\n", isHuiWenChuan("ababa"));
    printf("%d\n", isHuiWenChuan("ababab"));
}
