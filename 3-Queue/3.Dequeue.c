#include<stdio.h>
#include<stdlib.h>
int isFull();
int isEmpty();
void insertFromRear(int value);
void insertFromFront(int value);
int deleteFromRear();
int deleteFromFront();

#define SIZE 4
    int dQueue[SIZE];
    int front = -1;
    int rear = -1;
int main(){
    insertFromRear(3);
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear);
    insertFromRear(4);
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear);
    insertFromFront(2);
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear);
    deleteFromFront();     //4
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear); 
    insertFromFront(2);
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear);
    insertFromRear(3);
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear);
    deleteFromRear();     
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear); 

return 0;
}
int isEmpty(){
    if(front == -1 && rear == -1){
        return 1;
    }
    return 0;
}
int isFull(){
    if(front == 0 && rear == SIZE-1){
        return 1;
    }
    return 0;
}
void insertFromRear(int value){
    if(rear == SIZE-1){
        printf("Cannot be inserted at Rear End:\n");
    }else{
        rear = rear+1;
        dQueue[rear] = value;
        if(front = -1){
            front = 0;
        }
    }
}
void insertFromFront(int value){
    if(front == 0){
        printf("Cannot be inserted at Front End:\n");
    }else{
        front = front-1;
        dQueue[front] = value;
        if(rear == -1){
            rear = 0;
        }
    }
}
int deleteFromRear(){
    int value;
    if(front == rear){
        front = rear = -1;
    }else{
        value = dQueue[rear];
        rear = rear-1;
    }
    if(rear == 0){
        printf("Cannot be deleted at Rear End:\n");
    }
    return value;
}
int deleteFromFront(){
    int value;
    if(front == rear){
        front = rear = -1;
    }else{
        value = dQueue[front];
        front = front+1;
    }
    if(front == SIZE-1){
        printf("Cannot be deleted at Front End:\n");
    }
    return value;
}