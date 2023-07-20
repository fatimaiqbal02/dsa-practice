#include<stdio.h>
#define SIZE 4
int queue[SIZE];
int front = -1, rear = -1;
int isEmpty(){
    if(front == -1 && rear == -1){
        return 1;
    }return 0;
}
int isFull(){
    if(rear == SIZE-1){
        return 1;
    }return 0;
}
void enqueue(int value){
    if(isFull()){
        printf("Cannot be inserted:\n");
        printf("Queue is Full:\n");
    }else{
        rear = rear+1;
        queue[rear] = value;
        printf("%d is enqueued succesfully in Queue:\n",value);
        if(front == -1){
            front = 0;
        }
    }
}
int dequeue(){
    int value;
    if(isEmpty()){
        printf("Cannot be deleted:\n");
        printf("Queue is Empty:\n");
    }else{
        if(front == rear){
            value = queue[front];
            front = rear = -1;
        }else{
            value = queue[front];
            front = front+1;
        }
        printf("%d is dequeued succesfully from Queue:\n",value);
    }
    return value;
}
int main(){
    if(isEmpty()){
        printf("Queue is Empty:\n");
    }else{
         printf("Queue is Not Empty:\n");
    }
    enqueue(2);
    enqueue(4);
    enqueue(6);
    enqueue(8);
    enqueue(10);  //cannot be inserted
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    /*dequeue();  //cannot be deleted */
    enqueue(10);     //cannot be enqueue even having space
}