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
void selectionSort(int arr[], int size){
    int minIndex;
    for(int i = 0; i<size; i++){
        minIndex = i;
        for(int j = i+1; j<size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}
int main(){
    int arr[] = {3,5,2,12,13};
    int n = 5;
    printArray(arr,n);
    selectionSort(arr,n);
    printArray(arr,n);
}