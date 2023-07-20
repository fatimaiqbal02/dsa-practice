#include<stdio.h>
int size = 0;
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int size, int i){
    int parentNode = i;
    int l_child = 2*i+1;
    int r_child = 2*i+2;
    if(l_child<size && arr[l_child] > arr[parentNode]){
        swap(&arr[l_child],&arr[parentNode]);
    }
    else if(r_child<size && arr[r_child] > arr[parentNode]){
        swap(&arr[r_child],&arr[parentNode]);
    }
}
void insert(int arr[],int data){
    if(size == 0){
        arr[0] = data;
        size++;
    }else{
        arr[size] = data;
        size++;
        int i = size/2 -1;
        while(i!=-1){
            heapify(arr,size,i);
            i--;
        }
    }
}
void delete(int arr[]){
    printf("%d\t",arr[0]);
    swap(&arr[0], &arr[size-1]);
    size--;
    int i = size/2 -1;
    while(i!=-1){
        heapify(arr,size,i);
        i--;
    }
}
void print(int arr[], int size){
    for(int i = 0; i<size;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[7];
    insert(arr,15);
    insert(arr,4);
    insert(arr,2);
    insert(arr,17);
    insert(arr,20);

   
    print(arr,size);
    printf("Printing in Order - (Max to min):\n");
    while(size!=0){
        delete(arr);
    }
}