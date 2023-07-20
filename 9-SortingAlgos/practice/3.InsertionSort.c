//compare element with next element
//if less then compare with next elemnt
//then replace
#include<stdio.h>
void InsertionSort(int arr[], int size){
    int key,j;
    for(int i =1; i<size;i++){
        key = arr[i];
        j = i;
        while(j>0 && arr[j-1]> key){
            arr[j] = arr[j-1];
            j--;
        }
       arr[j] = key;
    }
}
int main(){

}