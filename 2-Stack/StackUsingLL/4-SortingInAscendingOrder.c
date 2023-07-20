#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*link;
}; 
struct Node *top = NULL;
int isEmpty(){
    if(top == NULL){
        return 1;
    }return 0;
}
int isFull(){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    if(ptr == NULL){
        return 1;
    }return 0;
}
void push(int data){
    if(isFull()){
        printf("Cannot be pushed:\n");
        printf("Stack Overflow\n");
    }else{
        struct Node*ptr =  (struct Node*)malloc(sizeof(struct Node));
        ptr->data = data;
        ptr->link = top;
        top = ptr;
        printf("%d is pushed succesfully in stack:\n",data);
    }
    
}
int pop(){
    int data;
    if(isEmpty()){
        printf("Cannot be pushed:\n");
        printf("Stack Overflow\n");
    }else{
        struct Node*ptr =  top;
        data = ptr->data;
        printf("%d is popped succesfully in stack:\n",ptr->data);
        top = top->link;
        free(ptr);  
    }
    return data;
    
}
void display(){
    struct Node*ptr = top;
    int i = 0;
    if(top == NULL){
        printf("Stack is Empty:\n");
    }else{
        while(ptr!=NULL){
            printf("Data at Node %d = %d\n",i,ptr->data);
            ptr = ptr->link;
            i++;
        }
    }
}
void sortingInAscendingOrder(){
    int temp;
    struct Node*p = top;
    struct Node*q;
    while(p->link!=NULL){
        q = p->link;
        while(q->link!=NULL){
            if(p->data > q->data){
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->link;
        }
        p = p->link;
    }
}
int main(){

  int data;
  for(int i = 0; i<4;i++){
      printf("Enter the value to be pushed in Stack:\n");
      scanf("%d",&data);
      push(data);
  }
   display();
   sortingInAscendingOrder();
   display();
}