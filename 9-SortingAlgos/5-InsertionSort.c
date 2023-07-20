#include<stdio.h>
void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
void insertionSort(int arr[], int size){
    int key;
    for (int i = 1; i<size ; i++)
    {
      int j = i;
      key = arr[i];
      while(j>0 && arr[j-1] > key){
          arr[j] = arr[j-1];
          j--;
      }
        arr[j] = key;
    }
    
}
int main(){
    int arr[] = {7,2,91,77,3};
    int n = 5;
    printArray(arr,n);
    insertionSort(arr,n);
    printArray(arr,n);
}