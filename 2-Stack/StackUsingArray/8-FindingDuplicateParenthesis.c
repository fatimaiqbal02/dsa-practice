#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 5
    int stack[SIZE];
    int top = -1;

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

void duplicateParenthesisCheck(char string[]){
    int flag = 0;
    int i = 0;
    while(i<strlen(string)){
         if(string[i] == '('){
            push(string[i]);
            i++;
        }else if(string[i] != '(' && string[i] != ')'){
             //printf("%c\n",string[i]);
             i++;
        }else if(string[i] == ')' && stack[top] == '('){
            pop();
            i++;
            flag = 1;
            //printf("Flag = %d\n",flag);
            if(flag == 1){
                if(string[i] == ')' && stack[top] == '(' && i<strlen(string)-1){
                    pop();
                    i++;
                    flag = 2;
                    //printf("Flag = %d\n",flag);
                    break;
                }
            }
        }
    }
       
    if(flag == 2){
        printf("Expression contain duplicate Parenthesis:\n");
    }else{
         printf("Expression does not contain duplicate Parenthesis:\n");
    }
}
int main(){

    char string[50];
    printf("Enter the String:\n");
    gets(string);
    duplicateParenthesisCheck(string);
    

return 0;
}