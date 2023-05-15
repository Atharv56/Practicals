// Quick sort

#include<stdio.h>

int partition(int arr[], int low, int high);

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void quicksort(int arr[], int s, int e){
    if(s < e){
        int p = partition(arr, s,e);
        quicksort(arr, s, p-1);
        quicksort(arr, p+1, e);
    }
}

void main(){
    int arr[] = {7,6,2,1,8};
    int n = 5;
    quicksort(arr, 0, n-1);
    for (int i = 0; i<n; i++){
        printf("%d", arr[i]);
    }
    
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // end points to the ending of the array
    int k = high;
    int n=5;
    
    for (int i = high; i > low; i--) 
    {
        for (int s = 0; s < n; s++)
                printf("%d ",arr[s]);
        printf("\n");
            
        if (arr[i] > pivot)
        {
            printf("%d %d %d \n", arr[i], arr[k], pivot);
            swap(&arr[i], &arr[k--]);
        }
        printf("\n\n");
    }
    swap(&arr[low], &arr[k]);
    return k;
}

