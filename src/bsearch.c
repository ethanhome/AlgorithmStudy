#include<stdio.h>
#include<stdlib.h>

int bSearch(int a[], int n, int x){
    int low, high;
    int mid;
    low = 0;
    high = n-1;

    while(low<=high){
        mid = low +(high-low)/2; 
        if (a[mid] == x){
            return mid; 
        }else if (a[mid]> x){
            high = mid -1; 
        }else {
            low = mid + 1; 
        }
    }
    return -1;
}

int bSearchFirstEqual(int a[], int n, int x){
    int low, high, mid;
    low = 0;
    high = n-1;

    while(low<=high){
        mid = low + (high-low)/2; 
        if(a[mid]>x){
            high = mid - 1;
        }else if (a[mid]< x){
            low = mid + 1; 
        }else {
            if(mid == 0 || (a[mid-1]!=x)) 
                return mid;
            high = mid - 1;
        }
    }
    return -1;
}

int bSearchLastEqual(int a[], int n, int x){
    int low, high, mid;
    low = 0;
    high = n-1;

    while(low<=high){
        mid = low + (high-low)/2; 
        if(a[mid]>x){
            high = mid - 1;
        }else if (a[mid]< x){
            low = mid + 1; 
        }else {
            if(mid == n-1 || (a[mid+1]!=x)) 
                return mid;
            low = mid + 1;
        }
    }
    return -1;
}

int bSearchFirstEqualOrLarge(int a[], int n, int x){
    int low, high, mid;
    low = 0;
    high = n-1;

    while(low<=high){
        mid = low + (high-low)/2; 
        if(a[mid]>=x){
            if (mid == 0 || (a[mid-1]< x))
                return mid;
            high = mid - 1;
        }else {
            low = mid + 1; 
        }
    }
    return -1;
}
int bSearchLastEqualOrSmall(int a[], int n, int x) {
    int low, high, mid;
    low = 0;
    high = n-1;

    while(low<=high){
        mid = low + (high-low)/2; 
        if(a[mid]<=x){
            if (mid == n-1 || (a[mid+1]>x))
                return mid;
            low = mid + 1; 
        }else {
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int a[5] = {1,2,3,4,5};
    printf("%d\n", bSearch(a, 5, 4));
    int a1[5] = {1,2,2,3,3};
    printf("firstEq:%d\n", bSearchFirstEqual(a1, 5, 2));
    printf("LastEq:%d\n", bSearchLastEqual(a1, 5, 2));
    printf("firstEqOrLarge:%d\n", bSearchFirstEqualOrLarge(a1, 5, 3));
    printf("LastEqOrSmall:%d\n", bSearchLastEqualOrSmall(a1, 5, 3));
}
