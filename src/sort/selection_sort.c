#include<stdio.h>
#include<stdlib.h>

void selection_sort(int* arr, int len){
    int i, j;
    int index;
    int tmp;
    if (len <= 1)
        return;
    for(i=0; i<len; i++){
        index = i; 
        for(j=i+1;j<len; j++){
            if(arr[j]< arr[index]){
                index = j; 
            } 
        }  
        if (index != i){
            //swap 
            tmp = arr[i];
            arr[i] = arr[index];
            arr[index] = tmp;
        }
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
    selection_sort(a, 5);
    print_arr(a, 5);
}
