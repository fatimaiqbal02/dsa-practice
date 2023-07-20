#include<stdio.h>
void inputArray(int arr[],int size){
    for(int i = 0; i<size; i++){
         printf("Enter the element at Index %d :\n",i);
         scanf("%d",&arr[i]);
    }
}
void printArray(int arr[],int size){
    for(int i = 0; i<size;i++){
        printf("%d \t",arr[i]);
    }
}
void findingPrevSmallerElement(int arr[],int arr2[],int size){
    for(int i = size-1; i>=0; i--){
        int prev = -1;
        for(int j = i-1; j>=0; j--){
            if(arr[i] > arr[j]){
                prev = arr[j];
                break;
            }
        }
        arr2[i] = prev;
    }
}
int main(){
    int arr[10];
    int arr2[10];
    int minMax;
    int size;

    printf("Enter the size of Array :\n");
    scanf("%d",&size);
    inputArray(arr,size);
    printArray(arr,size);
    findingPrevSmallerElement(arr,arr2,size);
    printf("\n");
    printArray(arr2,size);
}
