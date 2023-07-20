#include<stdio.h>
    #define SIZE 4
    int stack[SIZE];
    int top  = -1;
    int result[SIZE];
int isEmpty(){
    if(top < 0 ){
        return 1;
    }
    return 0;
}
int isFull(){
    if(top == SIZE-1){
        return 1;
    }
    return 0;
}
void push(int value){
    if(isFull(top)){
        printf("Cannot be pushed:\n");
        printf("Stack Overflow\n");
    }else{
        top = top+1;
        stack[top] = value;
        printf("%d is pushed succesfully in stack:\n",value);
    }
}
int pop(){
    int value;
    if(isEmpty(top)){
        printf("Cannot be popped:\n");
        printf("Stack Underflow\n");
    }else{
        value = stack[top];
        top--;
        printf("%d is successfully popped out of stack:\n",value);
    }
    return value;
}
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
    printf("\n");
}
void FindingPrevSmallerElement(int input[]){ 
    for(int i = 0; i<SIZE; i++){
        result[i] = -1;
    }

    for(int i = 0; i<SIZE;i++){
        while(!isEmpty()){
            if(input[i] > stack[top]){
                result[i] = stack[top];
                break;
            }else{
                pop();
            }
        }
        push(input[i]);
    }
}
int main(){
    int input[SIZE];
    inputArray(input,4);
    printArray(input,4);
    FindingPrevSmallerElement(input);
    printArray(result,4);
}