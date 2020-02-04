#include<stdio.h>
#include<stdlib.h>

void swap(int a[], int i, int j){
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
void heapify(int a[], int n, int i){
    int maxPos;
    while(1){
        maxPos = i;
       if(i*2 <= n && a[i]<a[i*2]) 
           maxPos = i*2;
       if(i*2+1 <= n && a[maxPos]<a[i*2+1])
           maxPos = i*2+1;
       if (maxPos == i)
           break;
       swap(a, i, maxPos);
       i = maxPos;
    }
}
void build_heap(int a[], int len){
    int i;
    for (i=len/2; i>=1; i--){
        heapify(a, len, i) ;
    }
}
void heap_sort(int a[], int n){
    build_heap(a, n);
    int k = n;
    while(k > 1) {
        swap(a, 1, k); 
        --k;
        heapify(a, k, 1);
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
    //a[0] 不用
    int a[6]={0,5,3,4,1,2};
    print_arr(a, 6);
    heap_sort(a, 5);
    print_arr(a, 6);
}
