#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5
int isEmpty();
int isFull();
void push(char value);
void display();
void balancedExpressionCheck(char string[]);
char pop();
    int stack[SIZE];
    int top = -1;
int main(){

    char string[50];
    printf("Enter the String:\n");
    gets(string);
    balancedExpressionCheck(string);
    

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
void push(char value){
    if(isFull(top)){
        printf("Cannot be pushed:\n");
        printf("Stack Overflow\n");
    }else{
        top = top+1;
        stack[top] = value;
        printf("%c is pushed succesfully in stack:\n",value);
    }
}
char pop(){
    int value;
    if(isEmpty(top)){
        printf("Cannot be popped:\n");
        printf("Stack Underflow\n");
    }else{
        value = stack[top];
        top--;
        printf("%c is successfully popped out of stack:\n",value);
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
  
void balancedExpressionCheck(char string[]){
    int length = 0;
    for(int i = 0; i<strlen(string); i++){
         if(string[i] == '[' || string[i] == '{' || string[i] == '('){
             push(string[i]);
         }else if(string[i] == ']' || string[i] == '}' || string[i] == ')'){
             if(string[i] == ']' && stack[top] == '[' || string[i] == ')' && stack[top] == '(' || string[i] == '}' && stack[top] == '{'){
                 pop();
                 length++;
             }
         }
    }
    if(isEmpty()){
        printf("Expression is Balanced:\n");
    }else{
        printf("Expression is Not Balanced:\n");
    }
    printf("Length = %d\n",length);
}
