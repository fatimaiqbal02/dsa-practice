//compare with all other and find min and then replace
#include<stdio.h>
void swap(int *a, int*b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void selectionSort(int arr[], int size){
    int minIndex;
    for(int i=0; i<size;i++){
        minIndex = i;
        for(int j=i+1;j<size;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(&arr[minIndex],&arr[i]);
    }
}
int main(){

}
