#include<stdio.h>
#define SIZE 5
    int queue[SIZE];
    int front = -1, rear = -1;
int isEmpty(){
    if(front == -1 && rear == -1){
        return 1;
    }return 0;
}
int isFull(){
    if(front == 0 && rear == SIZE-1){
        return 1;
    }else if(rear == front-1){
        return 1;
    }return 0;
}
void enqueue(int value){
    if(isFull()){
        printf("Cannot be inserted:\n");
        printf("Queue is Full:\n");
    }else{
        if(rear != SIZE-1){
            rear = rear+1;
            queue[rear] = value;
        }else if(front!= 0 && rear == SIZE-1){
            rear = 0;
            queue[rear] = value;
        }if(front == -1){
            front = 0;
        }
        printf("%d is enqueued succesfully in Queue:\n",value);
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
        }else if(front == SIZE-1 && rear!=front){
            value = queue[front];
            front = 0;
        }else{
            value = queue[front];
            front = front + 1;
        }
     printf("%d is dequeued succesfully from Queue:\n",value);
    }
    return value;
}
void sortingQueue(){
    int temp;
    if(rear < front){
        for(int i = rear;i<SIZE;i++){
            for(int j = i+1;j<SIZE;j++){
                    if(queue[i] > queue[j]){
                    temp = queue[i];
                    queue[i] = queue[j];
                    queue[j] = temp;
                }
            }
        }
    }else if(front <= rear){
        for(int i = front;i<SIZE;i++){
            for(int j = i+1;j<SIZE;j++){
                    if(queue[i] > queue[j]){
                    temp = queue[i];
                    queue[i] = queue[j];
                    queue[j] = temp;
                }
            }
        }
    }

}
void display(){
    if(front <= rear){
        for(int i = front; i<=rear;i++){
            printf("%d\t",queue[i]);
        }
    }else if(rear < front){
        for(int i = front; i<SIZE; i++){
             printf("%d\t",queue[i]);
        }
        for(int i = rear; i<front;i++){
             printf("%d\t",queue[i]);
        }
    }
    printf("\n");
}
int main(){
    enqueue(2);
    enqueue(5);
    enqueue(4);
    enqueue(2);
    enqueue(7);
    display();

    dequeue();
    display();

    enqueue(1);
    display(); 
    sortingQueue();
    display();
}