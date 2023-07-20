#include<stdio.h>
int binarySearch(int arr[], int left, int right, int element){
    while(left<= right){

        int middle = left + (right-left)/2;

        if(arr[middle] == element){
            return middle;
        }else if(arr[middle] < element){
            left = middle+1;
        }else if(arr[middle] > element){
            right = middle-1;
        }   
    }
    return -1;
}
int main(){
    int arr[6] ={1,2,3,4,5,6};
    if(binarySearch(arr,0,6,4) == -1){
        printf("Element Not Found:\n");
    }else{
        printf("Element Found at Index %d:\n",binarySearch(arr,0,6,4));
    }
}
 