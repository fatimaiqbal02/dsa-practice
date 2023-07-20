#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 30
int isEmpty();
int isFull();
void push(char stack[],int *top,char value);
char pop(char stack[],int *top);
void infixToPostfix(char infix[]);
    char psnstack[SIZE];
    char opStack[SIZE];
    int psntop = -1;
    int opTop = -1;
int main(){
    char infix[50] = "9+(12+3)";
    infixToPostfix(infix);
    printf("The postfix expression is:\n");
    puts(psnstack);
}
int isEmpty(int top){
    if(top < 0 ){
        return 1;
    }
    return 0;
}
int isFull(int top){
    if(top == SIZE-1){
        return 1;
    }
    return 0;
}
void push(char stack[],int* top,char value){
    if(isFull(*top)){
        printf("Cannot be pushed:\n");
        printf("Stack Overflow\n");
    }else{
        *top = *top+1;
        stack[*top] = value;
        printf("%c is pushed succesfully in stack:\n",value);
    }
}
char pop(char stack[],int *top){
    char value;
    if(isEmpty(*top)){
        printf("Cannot be popped:\n");
        printf("Stack Underflow\n");
    }else{
        value = stack[*top];
        *top = *top-1;
        printf("%c is successfully popped out of stack:\n",value);
    }
    return value;
}
int isOperator(char s){
    if(s == '+' || s == '-' || s == '/' || s == '*' || s == '^'){
        return 1;
    }return 0;
}
int Precedence(char s){
    if(s == '-' || s == '+'){
        return 2;
    }else if(s == '*' || s == '/'){
        return 3;
    }else if(s == '^'){
        return 4;
    }return 0;
}
void infixToPostfix(char infix[]){
    for(int i = 0; i<strlen(infix); i++){
        if(isdigit(infix[i])){
            push(psnstack,&psntop,infix[i]);
        }else{
            if(infix[i] == '('){
               push(opStack,&opTop,infix[i]);
            }else if(infix[i] == ')'){
                while(opStack[opTop] != '('){
                  char value = pop(opStack,&opTop);
                  push(psnstack,&psntop,value);
                }
                pop(opStack,&opTop);
            }else if(isOperator(infix[i])){
                if(Precedence(infix[i]) > Precedence(opStack[opTop])){
                    push(opStack,&opTop,infix[i]);
                }else{
                    while(Precedence(infix[i]) <= opStack[opTop]){
                        char popped = pop(opStack,&opTop);
                        push(psnstack,&psntop,popped);
                    }
                    push(opStack,&opTop,infix[i]);
                }
            } 
        } 
    }
     while(opStack[opTop] != '\0'){
        push(psnstack,&psntop,pop(opStack,&opTop));
    }
    push(psnstack,&psntop,'\0');
}