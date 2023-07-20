#include<stdio.h>
#define SIZE 4
int isEmpty(int queue[],int front, int rear){
    if(front == -1 && rear == -1){
        return 1;
    }return 0;
}
int isFull(int queue[],int front, int rear){
    if(front == 0 && rear == SIZE-1){
        return 1;
    }else if(rear == front-1){
        return 1;
    }return 0;
}
void enqueue(int queue[], int *front, int *rear, int value){
    if(isFull(queue,*front,*rear)){
        printf("Cannot be inserted:\n");
        printf("Queue is Full:\n");
    }else{
        if(*rear !=SIZE-1){
            *rear = *rear+1;
            queue[*rear] = value;
        }else if(*rear == SIZE-1){
            *rear = 0;
            queue[*rear] = value;
        }if(*front == -1){
            *front = 0;
        }
        printf("%d is enqueued succesfully in Queue:\n",value);
    }
}
int dequeue(int queue[], int *front, int *rear){
    int value;
    if(isEmpty(queue,*front,*rear)){
        printf("Cannot be deleted:\n");
        printf("Queue is Empty:\n");
    }else{
        if(*front == *rear){
            value = queue[*front];
            *front = *rear = -1;
        }
        else if(*front == SIZE-1 && *rear!= *front){
            value = queue[*front];
            *front = 0;
        }else{
            value = queue[*front];
            *front = *front+1;
        }
         printf("%d is dequeued succesfully from Queue:\n",value);
    }
    return value;
}
int main(){
    int Cqueue[SIZE];
    int front = -1, rear = -1;

    if(isEmpty(Cqueue,front,rear)){
        printf("Queue is Empty:\n");
    }else{
         printf("Queue is Not Empty:\n");
    }
    enqueue(Cqueue,&front,&rear,2);
    enqueue(Cqueue,&front,&rear,4);
    enqueue(Cqueue,&front,&rear,6);
    enqueue(Cqueue,&front,&rear,8);
    dequeue(Cqueue,&front,&rear);
    enqueue(Cqueue,&front,&rear,10);
    enqueue(Cqueue,&front,&rear,12);
}