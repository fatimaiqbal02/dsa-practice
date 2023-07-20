#include<stdio.h>
int isEmpty(int top);
int isFull(int top);
void push(int stack[],int*top,int value);
int pop(int stack[],int* top);
void enqueue(int value);
int dequeue();
#define SIZE 4
    int stack1[SIZE];
    int stack2[SIZE];
    int top1 = -1,top2 = -1;
int main(){
    enqueue(2);
    printf("Value of Top1 = %d\n",top1);
    enqueue(4);
    printf("Value of Top1 = %d\n",top1);
    enqueue(6);
    printf("Value of Top1 = %d\n",top1);
    enqueue(8);
    printf("Value of Top1 = %d\n",top1);
    /* enqueue(10);
    printf("Value of Top1 = %d\n",top1); */
    dequeue();
    printf("Value of Top2 = %d\n",top2);
    dequeue();
    printf("Value of Top2 = %d\n",top2);
    enqueue(9);
    printf("Value of Top1 = %d\n",top1);
    printf("Value of Top2 = %d\n",top2);
    dequeue();
    printf("Value of Top1 = %d\n",top1);
    printf("Value of Top2 = %d\n",top2);
    dequeue();
    printf("Value of Top1 = %d\n",top1);
    printf("Value of Top2 = %d\n",top2);
    dequeue();
    printf("Value of Top1 = %d\n",top1);
    printf("Value of Top2 = %d\n",top2);
   /*  dequeue();
    printf("Value of Top1 = %d\n",top1);
    printf("Value of Top2 = %d\n",top2); */
}
int isEmpty(int top){
    if(top < 0){
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
void enqueue(int value){
    int num;
    if(!isEmpty(top1)){
        push(stack1,&top1,value);
        if(top1<= SIZE-2){
              printf("abcd %d is successfully push into stack1\n",value);
              printf("%d is successfully enqued:\n",value);
        }
      
    }else{
        while(!isEmpty(top2)){
            num = pop(stack2,&top2);
            printf("%d is successfully popped out of stack2\n",num);
            push(stack1,&top1,num);
            printf("%d is successfully pushed into stack2\n",num);
        }
        push(stack1,&top1,value);
        printf("%d is successfully pushed into stack1\n",value);
        printf("%d is successfully enqued:\n",value);
    }
}
int dequeue(){
    int value;
    if(!isEmpty(top1)){
        while(!isEmpty(top1)){
             value = pop(stack1,&top1);
             push(stack2,&top2,value);
        }
        value = pop(stack2,&top2);
        printf("%d is successfully dequeued\n",value);
    }else if(!isEmpty(top2)){
        value = pop(stack2,&top2);
        printf("%d is successfully dequeued\n",value);
    }
    else{
        printf("Queue is Empty:\n Cannot be deleted:\n");
    }
    return value;
}
void push(int stack[],int* top,int value){
    if(isFull(*top)){
        printf("Stack is Full:\n %d Cannot be pushed:\n",value);
    }else{
        *top = *top+1;
        stack[*top] = value;
        printf("%d is successfully pushed into stack\n",value);
    }
}
int pop(int stack[],int* top){
    int value;
    if(isEmpty(*top)){
          printf("Stack is Empty:\n Cannot be popped:\n");
    }else{
        value = stack[*top];
        *top = *top-1;
        printf("%d is successfully popped out of stack\n",value);
    }
    return value;
}