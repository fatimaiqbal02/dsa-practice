#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*link;
};
struct Node*front,*rear = NULL;
int isEmpty(){
    if(front == NULL && rear == NULL){
        return 1;
    }return 0;
}
int isFull(){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL){
        return 1;
    }return 0;
}
void enqueue(int value){
    if(isFull()){
        printf("Cannot be inserted:\n");
        printf("Queue is Full:\n");
    }else{
        struct Node*ptr =  (struct Node*)malloc(sizeof(struct Node));
        ptr->data = value;
        ptr->link = NULL;
        if(front == NULL){
            front = rear = ptr;
        }else{
            rear->link = ptr;
            rear = ptr;
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
            value = front->data;
            front = rear = NULL;
        }else{
            struct Node*p = front;
            value = front->data;
            front = front->link;
            free(p);
        }
        
        printf("%d is dequeued succesfully from Queue:\n",value);
    }
    return value;
}
void display(){
    int i = 0;
    struct Node*p = front;
    if(p == NULL){
        printf("Queue is Empty:\n");
    }else{
        while(p!=NULL){
            printf("Data at Node %d = %d\n",i,p->data);
            p = p->link;
            i++;
       }
    }

}
int main(){
    display();
    enqueue(2);
    display();
    dequeue();
    display();
}