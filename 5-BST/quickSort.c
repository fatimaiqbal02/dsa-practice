#include<stdio.h>
void quickSort(int arr[], int low, int high){
    int j;
    if(low < high){
    j = partition(arr,low,high);
    quickSort(arr,low,j-1);
    quickSort(arr,j+1,high);
    }
}
int division(int arr[], int low, int high){
   int v,i,j,temp;
   v= arr[low];
   i = low;
   j = high+1;
   do{
       do{
           i++;
       }while(arr[i] < v && i<=high);
    do{
        j--;
    }while(v < arr[j]);
   }while();
}
int main(){
    int arr[6] = {2,6,4,1,9,0};

}
