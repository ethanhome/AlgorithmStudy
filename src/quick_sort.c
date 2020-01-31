#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int q, int r){
    int i,j;
    int pivot = arr[r];
    i = q;
    for(j=q; j<r; j++){
        if(arr[j]<pivot) {
            swap(&arr[j], &arr[i]);             
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
int randomPartition(int arr[], int q, int r){
    int i = q + rand()%(r-q+1);
    swap(&arr[i], &arr[r]);
    return partition(arr, q, r); 

}

void quick_sort(int arr[], int q, int r){
    int p;
    if(q>= r)
        return;
    //p = partition(arr, q, r);
    p = randomPartition(arr, q, r);
    quick_sort(arr, q, p-1);
    quick_sort(arr,p+1, r);
}

void print_arr(int* arr, int len){
    int i;
    for(i=0; i<len; i++){
        printf("%d, ", arr[i]); 
    }
    printf("\n");
}
// kth min,  kth max should change a little in partition function
int get_min_kth(int arr[], int n, int k){
    int low = 0;
    int high = n-1;
    int j;

    while(low < high) {
        j = partition(arr, low, high); 
        if (j+1 == k){
            return arr[j]; 
        }else if (j+1 < k){
            low = j+1; 
        }else {
            high = j-1; 
        }
    } 
    return arr[k-1];
}

int main(){
    int a[5]={5,4,3,2,1};
    print_arr(a, 5);
    quick_sort(a, 0, 4);
    print_arr(a, 5);
    printf("%d\n", get_min_kth(a, 5, 4));
}
