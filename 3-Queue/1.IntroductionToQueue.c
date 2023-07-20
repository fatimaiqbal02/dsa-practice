#include<stdio.h>
int isEmpty();
int isFull();
void insert(int value);
int delete();
void display();
#define SIZE 4
    int queue[SIZE];
    int front = -1;
    int rear = -1;
int main(){
    if(isEmpty()){
        printf("Queue is Empty:\n");
    }else{
        printf("Queue is Not Empty:\n");
    }
    insert(2);
    insert(4);
    insert(6);
    insert(8);
    display();
    delete();
    delete();
    display();
    
    if(isFull()){
        printf("Queue is Full:\n");
    }else{
        printf("Queue is Not Full:\n");
    }
    insert(8);
}
int isEmpty(){
    if(front == -1 || rear == -1){
        return 1;
    }
    return 0;
}
int isFull(){
    if(rear == SIZE-1){
        return 1;
    }
    return 0;
}
void insert(int value){
    if(isFull()){
        printf("Queue is Full:\n");
        printf("Cannot be inserted:\n");
    }else{
        rear = rear+1;
        queue[rear] = value;
        if(front == -1){
            front = front+1;
        }
    }
}
int delete(){
    int value;
    if(isEmpty()){
        printf("Queue is Empty:\n");
        printf("Cannot be deleted:\n");
    }else{
        if(front == rear){
            value = queue[front];
            front = rear = -1;
        }else{
            value = queue[front];
            front = front+1;
        }
    }
    return value;
}
void display(){
    for(int i = front; i<=rear;i++){
        printf("%d \t",queue[i]);
    }
    printf("\n");
}
/*
Queue is Empty:
2       4       6       8 
6       8
Queue is Full:
Queue is Full:
Cannot be inserted:
*/