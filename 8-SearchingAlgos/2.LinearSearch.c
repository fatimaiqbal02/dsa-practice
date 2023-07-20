#include<stdio.h>
int linearSearch(int arr[],int size, int element){
    for(int i = 0; i<size; i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}
int main(){
    int arr[6] ={1,2,3,4,5,6};
    if(linearSearch(arr,6,4) == -1){
        printf("Element Not Found:\n");
    }else{
        printf("Element Found at Index %d:\n",linearSearch(arr,6,4));
    }
}