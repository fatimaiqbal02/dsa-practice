#include<stdio.h>
#include<stdlib.h>
int isEmpty(int front,int rear);
int isFull(int rear);
void insert(int value,int level,int* front,int* rear);
int delete(int level,int* front,int* rear);
void display();
#define SIZE 4
    int queue[3][SIZE];
    int front1 = -1, rear1 = -1;
    int front2 = -1, rear2 = -1;
    int front3 = -1, rear3 = -1;
int main(){
    if(isEmpty(front1,rear1)){
        printf("Queue row 1 is Empty:\n");
    }else{
        printf("Queue row 1 is Not Empty:\n");
    }

    if(isEmpty(front2,rear2)){
        printf("Queue row 2 is Empty:\n");
    }else{
        printf("Queue row 2 is Not Empty:\n");
    }

    if(isEmpty(front3,rear3)){
        printf("Queue row 3 is Empty:\n");
    }else{
        printf("Queue row 3 is Not Empty:\n");
    }
    //display();

    insert(1,0,&front1,&rear1);
   // printf("The value of rear 1 is %d\n",rear1);
    insert(2,0,&front1,&rear1);
   // printf("The value of rear 1 is %d\n",rear1);
    insert(3,0,&front1,&rear1);
   // printf("The value of rear 1 is %d\n",rear1);
    insert(4,0,&front1,&rear1);
    //printf("The value of rear 1 is %d\n",rear1);

    insert(5,1,&front2,&rear2);
   // printf("The value of rear 2 is %d\n",rear2);
    insert(6,1,&front2,&rear2);
   // printf("The value of rear 2 is %d\n",rear2);
    insert(7,1,&front2,&rear2);
   // printf("The value of rear 2 is %d\n",rear2);
    insert(8,1,&front2,&rear2);
   // printf("The value of rear 2 is %d\n",rear2);

    insert(9,2,&front3,&rear3);
    //printf("The value of front 3 is %d\n",front3);  
    //printf("The value of rear 3 is %d\n",rear3);
    insert(10,2,&front3,&rear3);
    //printf("The value of front 3 is %d\n",front3);  
    //printf("The value of rear 3 is %d\n",rear3);
    insert(11,2,&front3,&rear3);
    //printf("The value of front 3 is %d\n",front3);  
    //printf("The value of rear 3 is %d\n",rear3);
    insert(12,2,&front3,&rear3);
    //printf("The value of front 3 is %d\n",front3);  
    //printf("The value of rear 3 is %d\n",rear3);

    display();
    /* insert(12,2,front3,&rear3);
    printf("The value of rear 3 is %d\n",rear3);
    display(); */   //cannot be inserted..
    delete(2,&front3,&rear3);
    delete(0,&front1,&rear1);
 //   delete(4,&front3,&rear3);
   // printf("The value of rear 3 is %d\n",rear3);
   // printf("The value of front 3 is %d\n",front3);
    display();

return 0;
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
void insert(int value,int level,int* front,int *rear){
    if(isFull(*rear)){
        printf("Queue is Full:\n");
        printf("Cannot be inserted:\n");
    }else{
        *rear = *rear+1;
      //  printf("%d\n",rear);
        queue[level][*rear] = value;
        if(*front == -1){
            *front = 0;
        }
    }
}
int delete(int level,int* front,int* rear){
    int value;
    if(isEmpty(*front,*rear)){
        printf("Queue is Empty:\n");
        printf("Cannot be deleted:\n");
    }else{
        value = queue[level][*front];
        if(*front == *rear){
            *front = *rear = -1;
        }else{
            *front = *front+1;
        }
    }
    return value;
}
void display(){
    for(int i = 0; i<3;i++){
        if(i == 0){
            for(int j = front1; j<=rear1;j++){
                printf("%d\t ",queue[i][j]);
        }
        }else if(i ==1){
            for(int j = front2; j<=rear2;j++){
                printf("%d\t ",queue[i][j]);
        }
        }else if(i ==2){
            for(int j = front3; j<=rear3;j++){
                printf("%d\t ",queue[i][j]);
        }
        }
         printf("\n");
        }
}