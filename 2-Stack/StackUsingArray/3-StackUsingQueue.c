#include<stdio.h>
#include <stdlib.h>
int isEmpty(int front,int rear);
int isFull(int rear);
void push(int value);
int pop();
void enqueue(int queue[],int value,int* front, int* rear);
int dequeue(int queue[], int* rear,int* front);
#define SIZE 4
    int front1 =-1,front2 = -1;
    int rear1 =-1, rear2 = -1;
    int queue1[SIZE];
    int queue2[SIZE];
int main(){
    push(2);
    push(4);
    push(6);
    push(8);
    push(10);
    pop();
    pop();
    pop();
    pop();
    pop(); 
    printf("Front 1 = %d\n",front1);
    printf("Rear 1 = %d\n",rear1);
    printf("Front 2 = %d\n",front2);
    printf("Rear 2 = %d\n",rear2);
}
int isEmpty(int front,int rear){
    if(front == -1 && rear == -1){
        return 1;
    }
    return 0;
}
int isFull(int rear){
    if(rear == SIZE-1){
        return 1;
    }
    return 0;
}
void push(int value){
    if(isEmpty(front1,rear1)){
        enqueue(queue2,value,&front2,&rear2);
        if(rear2 <= SIZE-2){
            printf("%d is pushed successfully into Queue2:\n",value);
            printf("Rear 2 Value check = %d\n",rear2);
            printf("Front 2 Value check = %d\n",front2);
            printf("%d is pushed successfully into Stack:\n",value);
        }     
    }
    else{
        enqueue(queue1,value,&front1,&rear1);
        if(rear2 <= SIZE-2){
            printf("%d is pushed successfully into Queue1:\n",value);
            printf("Rear 1 Value check = %d\n",rear1);
            printf("Front 1 Value check = %d\n",front1);
            printf("%d is pushed successfully into Stack:\n",value);
        }     
    }
}
int pop(){
     int value;
     if(isEmpty(front1,rear1)){
            if(isEmpty(front2,rear2)){
                  printf("Stack Underflow: Cannot be deleted:\n");
                  exit(0);
            }
     }
     else if(isEmpty(front2,rear2)){
            if(isEmpty(front1,rear1)){
                  printf("Stack Underflow: Cannot be deleted:\n");
                  exit(0);
            }
     }
    if(!isEmpty(front1,rear1)){
        while(front1 != rear1){
           value = dequeue(queue1,&rear1,&front1);
           printf("%d is dequeued successfully from Queue1;\n",value);
           enqueue(queue2,value,&front2,&rear2);
        }
          value = dequeue(queue1,&rear1,&front1);
    }else if(!isEmpty(front2,rear2)){
        while(front2 != rear2){
            value = dequeue(queue2,&rear2,&front2);
            printf("%d is dequeued successfully from Queue2;\n",value);
            enqueue(queue1,value,&front1,&rear1);
        }
        value = dequeue(queue2,&front2,&rear2);
    }
    printf("%d is popped successfully from Stack:\n",value);
    return value;
}
void enqueue(int queue[],int value,int* front,int* rear){
    if(isFull(*rear)){
         printf("Queue is Full:\n Cannot be inserted:\n");
    }else{
        *rear = *rear+1;
        queue[*rear] = value;
        if(*front == -1){
            *front = 0;
        }
        printf("%d is successfully pushed into Queue;\n",value);
    }
}
int dequeue(int queue[],int* rear,int* front){
    int value;
    if(isEmpty(*front,*rear)){
        printf("Queue is Empty:\n Cannot be deleted:\n");
    }else{
        if(*front == *rear){
            value = queue[*front];
            *front = *rear = -1;
        }else{
            value = queue[*front];
            *front = *front+1;
        }
        printf("%d is dequeued successfully from Queue;\n",value);
    }
    return value;
}
