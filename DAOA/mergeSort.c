//Mergesort

#include <stdio.h>

void merge(int arr[], int low, int mid, int high){
    int i = low, j = mid+1, k = low, p, temp[100];
    
    while(i <= mid && j <= high){
        if(arr[i] >= arr[j])
            temp[k++] = arr[j++];
        else
            temp[k++] = arr[i++];
            
    }
    while( i<= mid)
        temp[k++] = arr[i++];
    
    while ( j<=high)
        temp[k++] = arr[j++];
    
    for(p = low; p<=high; p++){
        arr[p] = temp[p];
    }
}

void mergeSort(int arr[], int low, int high){
    if (low < high){
        int mid = (low + high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
        
    }
}

void main(){
    int arr[] = {7,6,2,1,8};
    int n = 5;
    mergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    
}