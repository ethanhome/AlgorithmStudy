#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int* arr, int len){
    int i, j;
    int value;
    if (len <= 1)
        return;
    for(i=1; i<len; i++){
        value = arr[i]; 
        j = i - 1;
        for(;j>=0; j--) {
            
            if(arr[j]> value){
                arr[j+1] = arr[j]; 
            }else {
                break; 
            } 
        }
        arr[j+1] = value;
    }
}

void d_insertion_sort(int* arr, int len, int d){
    int i,j;
    int value;
    if(len<= 1)
        return;
    for(i=d; i<len; i+=d){
        value = arr[i]; 
        j = i-d;
        for(; j>=0; j-=d){
            if (arr[j]> value) {
                arr[j+d] = arr[j];
            }else {
                break; 
            }
        }
        arr[j+d] = value;
    }
}

void shell_sort(int* arr, int len){
    int d = len/2;
    for(;d>0;d=d/2){
        d_insertion_sort(arr, len, d);         
    }
}

void print_arr(int* arr, int len){
    int i;
    for(i=0; i<len; i++){
        printf("%d, ", arr[i]); 
    }
    printf("\n");
}
int main(){
    int a[5]={5,4,3,2,1};
    print_arr(a, 5);
    //insertion_sort(a, 5);
    shell_sort(a, 5);
    print_arr(a, 5);
}
