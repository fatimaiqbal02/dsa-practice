#include<stdio.h>
int divide(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low+1;
    int j = high;
    while(j>i){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(arr[j],arr[low]);
    return j;
   
}
void quickSort(int arr[], int low, int high){
    int mid;
    while(low < high){
        mid = divide(arr,low,high);
        quickSort(arr,low,mid-1);
        quickSort(arr,mid+1,high);
    }
}
int main(){}
