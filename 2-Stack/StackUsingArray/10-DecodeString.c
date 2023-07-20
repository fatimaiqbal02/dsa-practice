#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 25
void decodeString(char string[]);
    char extraStack[SIZE];
    int top = -1;

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
void reverseString(char string[]){
    
    for(int i = 0; i < strlen(string) ;i++){
         push(extraStack,&top,string[i]);
    }

    for(int i = 0; i<strlen(string) ;i++){
         string[i] = pop(extraStack,&top);
    }
}
void decodeString(char string[]){
    char numstack[SIZE];
    int numTop = -1;
    char charStack[SIZE];
    int charTop = -1;
    char bracesstack[SIZE];
    int bracesTop = -1;

    char word[2];
    int s = 0;

      fflush(stdin);
    char alphabet[] ="";
    int a = 0;

    int num = 0;
    for(int i = 0; i<strlen(string);i++){
        if(isdigit(string[i])){
            push(numstack,&numTop,string[i]);
        }else if(string[i] == '['){
            while(string[i] != ']'){
                push(bracesstack,&bracesTop,string[i]);
                i++;
            }

            while(!isEmpty(numTop)){
                   word[s] =  pop(numstack,&numTop);
                   s++;
               }
               //puts(word);
              /*  reverseString(word);
               puts(word); */
                for(int j = s-1;j>=0;j--){
                   num = num *10 + word[j] -'0';
               }
               printf("%d\n",num);  

        }
    }
}
int main(){
   char string[50];
   printf("Enter the Expression:\n");
   gets(string);
   decodeString(string);
}



















/* char substring[20];
    int j = 0;
    int m = 0;
    char k[] = "";
    for(int i = 0; i<strlen(string); i++){
        if(string[i] != ']'){
              push(string[i]);
        }else{
            while(stack[top] != '['){
                substring[j] = pop();
                printf("%c\n",substring[j]);
                j++;
            }
            pop();
            while(isdigit(stack[top])){
                k[m] = pop();
                printf("%c\n",k[m]);
                m++;
            }

        }    
       
    }
    puts(substring);
    puts(k); */