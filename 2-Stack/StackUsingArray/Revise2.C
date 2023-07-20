#include<stdio.h>
#define SIZE 6
    int stack1[SIZE];
    int stack2[SIZE];
    int top1 = -1, top2 = -1;
int isEmpty(int top){
    if(top < 0){
        return 1;
    }return 0;
}
int isFull(int top){
    if(top == SIZE-1){
        return 1;
    }return 0;
}
void push(int stack[],int *top, int value){
    if(isFull(*top)){
        printf("Stack is Full:\n %d Cannot be pushed:\n",value);
    }else{
        *top = *top+1;
        stack[*top] = value;
        printf("%d is successfully pushed into stack\n",value);
    }
}
int pop(int stack[], int *top){
    int value;
    if(isEmpty(*top)){
        printf("Stack is Empty:\n Cannot be popped:\n");
    }else{
        value = stack[*top];
        *top = *top - 1;
        printf("%d is successfully popped out of stack\n",value);
    }
    return value;
}
void enqueue(int value){
    int num;
    if(!isEmpty(top1)){
        push(stack1,&top1,value);
        printf("%d is successfully Enqueued\n",value);
    }else{
        while(!isEmpty(top2)){
                num = pop(stack2,&top2);
                push(stack1,&top1,num);
        }
        push(stack1,&top1,value);
        printf("%d is successfully Enqueued\n",value);
    }
}
int dequeue(){
    int value;
    int num;
    if(!isEmpty(top1)){
        while(!isEmpty(top1)){
            num = pop(stack1,&top1);
            push(stack2,&top2,num);
        }
        value = pop(stack2,&top2);
        printf("%d is successfully dequeued\n",value);
    }else{
        if(!isEmpty(top2)){
            value = pop(stack2,&top2);
            printf("%d is successfully dequeued\n",value);
        }
    }
    return value;
}  
void display(){
    for(int i = 0; i<top2; i++){
        printf("%d\t",stack2[i]);
    }
}
int main(){
        if(isEmpty(top1)){
            printf("Queue is Empty:\n");
        }else{
            printf("Queue is Not Empty:\n");
        }
        enqueue(2);
        enqueue(3);
        enqueue(4);
        dequeue();
        if(isEmpty(top1)){
            printf("Queue is Empty:\n");
        }else{
            printf("Queue is Not Empty:\n");
        }
        
}