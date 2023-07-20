/*
Name: Fatima Iqbal Mirza
Description: Three types of Delete Operations in Arrays
*/

#include<stdio.h>
#include<stdlib.h>
void deleteAtBeginning(int arr[],int size);
void deleteAtIndex(int arr[],int index,int size);
void deleteAtEnd(int arr[],int size);

int main(){
  int arr[10];
  int size;
  printf("Enter the size of Array:\n");
  scanf("%d",&size);
  for(int i = 0; i< size; i++){
        scanf("%d",&arr[i]);
   }
  for(int i = 0; i< size; i++){
        printf("%d ",arr[i]);
    }
    deleteAtEnd(arr,size);
    for(int i = 0; i< size-1; i++){
        printf("%d ",arr[i]);
    }
return 0;
}

void deleteAtBeginning(int arr[],int size){
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i+1];
    }
}

void deleteAtIndex(int arr[],int index,int size){
    for (int i = index; i < size-1; i++)
    {
      arr[i] = arr[i+1];
    }
}

void deleteAtEnd(int arr[],int size){
    arr[size] = 0;
}
