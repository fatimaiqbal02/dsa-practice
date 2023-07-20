#include<stdio.h>
int isEmpty();
int isFull();
void insert(int value);
int delete();
void display();
#define SIZE 4
    int cQueue[SIZE];
    int front = -1;
    int rear = -1;
int main(){
    if(isEmpty()){
        printf("Queue is Empty:\n");
    }else{
        printf("Queue is Not Empty:\n");
    }
    insert(2);
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear);
    insert(3);
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear);
    insert(4);
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear);
    insert(5);
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear);
    display();
    /* insert(6);
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear); 
    //cannot be inserted...
    */  
    delete();
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear);
    display();
    insert(6);
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear); 
    display();
    //insert(3); //cannot be inserted
    delete();
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear); 
    insert(7);
    printf("the value of front is %d:\n",front);
    printf("the value of rear is %d:\n",rear); 
    insert(3); //cannot be inserted
    
}
int isEmpty(){
    if(front == -1 && rear == -1){
        return 1;
    }
    return 0;
}
int isFull(){
    if(rear == front-1){
        return 1;
    }else if(front == 0 && rear == SIZE-1){
        return 1;
    }
    return 0;
}
void insert(int value){
    if(isFull()){
        printf("Queue is Full:\n");
        printf("Cannot be inserted:\n");
    }else{
        if(rear == SIZE-1){
            rear = 0;
            cQueue[rear] = value;
        }else{
            rear = rear+1;
            cQueue[rear] = value;
        }
        if(front == -1){
            front = 0;
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
            value = cQueue[front];
            front = rear = -1;
        }else if(front == SIZE-1){
            value = cQueue[front];
            front = 0;
        }else{
            value = cQueue[front];
            front = front+1;
        }
    }
    return value;
}
void display(){
    if(front < rear){
         for(int i = front; i<=rear;i++){
         printf("%d \t",cQueue[i]);
    }
         printf("\n");
    }else if(rear <front){
        for(int i = front; i<SIZE;i++){
         printf("%d \t",cQueue[i]);
    }
        for(int i = 0; i<=rear;i++){
         printf("%d \t",cQueue[i]);
    }
        printf("\n");
    }
}
/*
Queue is Empty:
the value of front is 0:   //2
the value of rear is 0:   
the value of front is 0:   //3
the value of rear is 1:   
the value of front is 0:  //4
the value of rear is 2:   
the value of front is 0:  //5
the value of rear is 3:   
2       3       4       5 
the value of front is 1:   //delete 2
the value of rear is 3:
3       4       5
the value of front is 1:   //6
the value of rear is 0:

the value of front is 2:   //delete 3
the value of rear is 0:
the value of front is 2:  //7
the value of rear is 1:
Queue is Full:           //3
Cannot be inserted:
*/