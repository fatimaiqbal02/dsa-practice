#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int isEmpty();
int isFull();
void push(int value);
void display();
int pop();
void sortingStack();
    int stack[SIZE];
    int top = -1;
int main(){

     push(3);
     printf("Top = %d\n",top);
     push(2);
     printf("Top = %d\n",top);
     push(4);
     printf("Top = %d\n",top);
     push(1);
     printf("Top = %d\n",top);
     display();
     sortingStack();
     display();
     pop();
     display(); 
return 0;
}
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
        //printf("%d is successfully popped out of stack:\n");
    }
    return value;
}
void display(){
    if(isEmpty()){
        printf("Stack is currently Empty:\n");
    }else{
        for (int i = 0; i<=top; i++)
        {
            printf("%d \t",stack[i]);
        }   
        printf("\n"); 
    }
}
void sortingStack(){
    int temp;
    for(int i = 0; i<= top; i++){
        for(int j = i+1; j<=top;j++){
            if(stack[i] > stack[j]){
                temp = stack[i];
                stack[i] = stack[j];
                stack[j] = temp;

            }
        }
    }
}