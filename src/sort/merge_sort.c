#include<stdio.h>
#include<stdlib.h>


void merge(int arr[], int low, int mid, int high){
    int len = high-low + 1;
    int* tempArr = (int*) malloc(sizeof(int)*len);
    int i = low;
    int j = mid+1;
    int k = 0;
    while(i<=mid && j<=high){
        if(arr[i]<arr[j]){
            tempArr[k++] = arr[i];
            i++;
        }else {
            tempArr[k++] = arr[j]; 
            j++;
        } 
    }
    for(;i<=mid; i++){
        tempArr[k++] = arr[i];
    }
    for(;j<=high; j++){
        tempArr[k++] = arr[j];
    }
    for(i=low; i<=high; i++){
        arr[i] = tempArr[i-low]; 
    }
}
void merge_sort(int arr[], int low, int high){
    if (low>=high)
        return;
    int mid = (low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
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
    merge_sort(a, 0, 4);
    print_arr(a, 5);
}
