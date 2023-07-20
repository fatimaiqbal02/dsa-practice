#include<stdio.h>
#define SIZE 5
    int queue1[SIZE];
    int queue2[SIZE];
    int rear1 = -1, rear2 = -1;
    int front1 = -1, front2 = -1;
int isEmpty(int rear, int front){
    if(rear == -1 && front == -1){
        return 1;
    }return 0;
}
int isFull(int rear){
    if(rear == SIZE-1){
        return 1;
    }return 0;
}
void enqueue(int queue[], int *rear,int *front ,int value){
    if(isFull(*rear)){
        printf("Queue is Full:\n Cannot be inserted:\n");
    }else{
        *rear = *rear + 1;
        queue[*rear] = value;
        if(*front == -1){
            *front = 0;
        }
    printf("%d is successfully pushed into Queue;\n",value);
    }
}
int dequeue(int queue[], int *rear, int*front){
    int value;
    if(isEmpty(*rear,*front)){
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
void push(int value){
    int num;
    if(!isEmpty(rear1,front1)){
        enqueue(queue1,&rear1,&front1,value);
        printf("%d is pushed successfully into Stack:\n",value);
    }else{
        while(!isEmpty(rear2,front2)){
            num = dequeue(queue2,&rear2,&front2);
            enqueue(queue1,&rear1,&front1,num);
        }
        enqueue(queue1,&rear1,&front1,value);
        printf("%d is pushed successfully into Stack:\n",value);
    }
}
int pop(){
    int value;
    int num;
    if(!isEmpty(rear1,front1)){
        while(!isEmpty(rear1,front1)){
            num = dequeue(queue1,&rear1,&front1);
            enqueue(queue2,&rear2,&front2,num);
        }
        value = dequeue(queue2,&rear2,&front2);
        printf("%d is popped successfully from Stack:\n",value);
    }else{
        value = dequeue(queue2,&rear2,&front2);
        printf("%d is popped successfully from Stack:\n",value);
    }
}
int main(){
    if(isEmpty(rear1,front1)){
            printf("Queue is Empty:\n");
    }else{
            printf("Queue is Not Empty:\n");
    }
    push(2);
    push(4);
    push(6);
    push(8);
    pop();
    
}