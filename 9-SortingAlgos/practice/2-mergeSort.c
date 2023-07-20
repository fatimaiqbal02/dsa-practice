//break array into smaller and smaller....
//
#include<stdio.h>
void merge(int arr[], int mid, int low,int high){
    int arr2[45];
    int k = 0;
    int i = low;
    int j = mid+1;
    while(i<=mid && j<=high){
        if(arr[i] < arr[j]){
            arr2[k] = arr[i];
            i++;
            k++;
        }
        if(arr[j] < arr[i]){
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
    if(i<=mid){
        while(i<=mid){
            arr2[k] = arr[i];
            i++;
            k++;
        }
    }
    if(j<=high){
        while(j<high){
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
    for(int i = low; i<=high; i++){
        arr[i] = arr2[i];
    }
}
void mergeSort(int arr[], int low, int high){
    int mid;
    while(low<high){
        mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,mid,low,high);
    }
}
int main(){

}