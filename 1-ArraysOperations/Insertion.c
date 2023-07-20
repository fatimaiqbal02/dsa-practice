/*
Name: Fatima Iqbal Mirza
Description: Three types of Insertion Operations in Arrays
*/

#include<stdio.h>
#include<stdlib.h>
int orignalSize =10;
void printArray(int arr[], int size);
void insertAtBeginning(int size,int arr[],int value);
void insertAtIndex(int size,int arr[],int value, int index);
void insertAtEnd(int size,int arr[],int value);
int isFull(int count);

int main(){
  int arr[10];
  int size;
  int count;
  printf("Enter the size of Array:\n");
  scanf("%d",&size);
  for(int i = 0; i< size; i++){
        scanf("%d",&arr[i]);
        count++;
    }
  printArray(arr,size);
 insertAtIndex(size,arr,3,2);
 for(int i = 0; i< size+1; i++){
        printf("%d ",arr[i]);
    }
 /*  insertAtBeginning(size,arr,9);
  for(int i = 0; i< size+1; i++){
        printf("%d ",arr[i]);
    } */
    /* insertAtEnd(size,arr,5);
    for(int i = 0; i< size+1; i++){
        printf("%d ",arr[i]);
    } */

return 0;
}
int isFull(int count){
    if(count == orignalSize-1){
        return 1;
    }
    return 0;
}
void printArray(int arr[], int size){
    for(int i = 0; i< size; i++){
        printf("%d ",arr[i]);
    }
}
void insertAtBeginning(int size,int arr[],int value){
   for (int i = size; i >= 0; i--)
    {
      arr[i+1] = arr[i];
    }
    arr[0] = value;
}  

void insertAtEnd(int size,int arr[],int value){
    arr[size] = value;
}

void insertAtIndex(int size,int arr[],int value, int index){
    if(isFull(size)){
        printf("Cannot be added");
    }else{
    for (int i = size; i >= index; i--)
     {
        arr[i+1] = arr[i];
     }
    arr[index] = value;
    }
    
}
