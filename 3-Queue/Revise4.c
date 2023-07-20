#include<stdio.h>
#define SIZE 4
int queue[SIZE];
int front = -1, rear = -1;
void insertionAtFront(int value){
    if(front <= 0){
        printf("Cannot be inserted:\n");
        printf("EnQueue is Not Possible:\n");
    }else{
        if(front > 0){
            front = front-1;
            queue[front] = value;
        }
        if(rear == -1){
            rear = 0;
        }
        printf("%d is enqueued succesfully in Queue:\n",value);
    }
}
void insertionAtRear(int value){
    if(rear == SIZE-1){
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
int deletionAtFront(){
    int value;
    if(front == -1 && rear == -1){
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
int deletionAtRear(){
    int value;
    if(rear <= 0){
        printf("Cannot be deleted:\n");
        printf("Queue is Empty:\n");
    }else{
        if(rear == front){
            rear = front = -1;
        }else{
            value = queue[rear];
            rear = rear-1;
        }
        printf("%d is dequeued succesfully from Queue:\n",value);
    }
    return value;
}
int main(){
    insertionAtRear(2);
    insertionAtRear(4);
    insertionAtRear(6);
    insertionAtRear(8);
    insertionAtRear(10);
    insertionAtFront(0);
    deletionAtRear();
    insertionAtRear(10);
    deletionAtFront();
    insertionAtFront(0);
}