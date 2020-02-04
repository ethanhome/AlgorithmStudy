#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int* arr, int len) {
    int i,j;
    int flag; 
    int tmp;
    if (len <= 1)
        return;
    for(i=0; i<len; i++) {
        flag = 0;
        for(j=0; j<len-i-1; j++){
            if(arr[j]>arr[j+1]){
                //swap
                tmp = arr[j];      
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                flag = 1;
            } 
        }        
        if (!flag)
            break;
    }

}
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
    bubble_sort(a, 5);
    print_arr(a, 5);
}
