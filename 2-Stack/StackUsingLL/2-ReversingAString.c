#include<stdio.h>
#include<stdlib.h>
#include <string.h>
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
        struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
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
        data = ptr->data;
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
            printf("Data at Node %d = %c\n",i,ptr->data);
            ptr = ptr->link;
            i++;
        }
    }
}
void reverseString(char string[]){
    char reverseString[25];
    for(int i = 0; i<strlen(string);i++){
        push(string[i]);
    }
    display();
     for(int i = 0; i<strlen(string);i++){
       reverseString[i] = pop();
    }
    puts(reverseString);
}
int main(){
   char string[50];
   printf("Enter a String to be Reversed:\n");
   gets(string);
   reverseString(string);
}