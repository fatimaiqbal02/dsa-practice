#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char data;
    struct Node*link;
}; 
struct Node *top = NULL;
int isEmpty(){
    if(top == NULL){
        return 1;
    }return 0;
}
int isFull(){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL){
        return 1;
    }return 0;
}
void push(char data){
    if(isFull()){
        printf("Cannot be pushed:\n");
        printf("Stack Overflow\n");
    }else{
        struct Node*ptr =  (struct Node*)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->link = top;
        top = ptr;
        printf("%c is pushed succesfully in stack:\n",data);
    }
    
}
char pop(){
    char data;
    if(isEmpty()){
        printf("Cannot be pushed:\n");
        printf("Stack Overflow\n");
    }else{
        struct Node*ptr =  top;
        char data = ptr->data;
        printf("%c is popped succesfully in stack:\n",ptr->data);
        top = top->link;
        free(ptr);
    }
    return data;
}
void display(){
    struct Node*ptr = top;
    int i = 0;
    if(top == NULL){
        printf("Stack is Empty:\n");
    }else{
        while(ptr!=NULL){
            printf("Data at Node %d = %d\n",i,ptr->data);
            ptr = ptr->link;
            i++;
        }
    }
}
void checkBalancedExpression(char exp[]){
    for(int i = 0; i<strlen(exp); i++){
        if(exp[i] == '(' || exp[i] == '{' || exp[i] == '['){
            push(exp[i]);
        }else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']'){
            if(exp[i] == ')' && top->data == '(' || exp[i] == ']' && top->data == '[' || exp[i] == '}' && top->data == '{'){
                pop();
            }else{
                break;
            }
        }
    }
    if(isEmpty()){
        printf("Expression is Balanced:\n");
    }else{
         printf("Expression is Not Balanced:\n");
    }
}
int main(){
   char string[50];
   printf("Enter the Expression:\n");
   gets(string);
   checkBalancedExpression(string);
}