#include<stdio.h>
void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int divide(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low+1;
    int j = high;

    while(j>i){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i < j){
          swap(&arr[i], &arr[j]);

        } 
    }
    
    swap(&arr[low], &arr[j]);
    return j;

}
void quickSort(int arr[], int low, int high){
    int breakPoint;
    if(low < high){
        breakPoint  = divide(arr, low, high);  //final index of pivot where we have to divide array
        quickSort(arr, low, breakPoint-1);
        quickSort(arr, breakPoint+1, high);
    }
}
int main(){
    int arr[] = {2,4,3,9,1,4,8,7,5,6};
    int n = 10;
    printArray(arr,n);
    quickSort(arr,0,n-1);
    printArray(arr,n);
}