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
void findingNextGreaterElement(int arr[],int arr2[],int size){
    int next;
    for(int i = 0; i<size; i++){
        next = -1;
        for(int j= i+1; j<size;j++){
            if(arr[i] < arr[j]){
                next = arr[j];
            break;
            }
        }
        arr2[i] = next;
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
    findingNextGreaterElement(arr,arr2,size);
    printf("\n");
    printArray(arr2,size);
}
