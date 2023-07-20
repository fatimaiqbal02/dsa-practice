#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
void createLinkedList(struct Node **head,int data){
    struct Node*ptr;
    if(*head == NULL){
        struct Node*firstNode = (struct Node*)malloc(sizeof(struct Node));
        firstNode->data = data;
        firstNode->next = firstNode;
        *head = ptr = firstNode;
    }else{
        struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = *head;
        while(ptr->next != *head){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        ptr = newNode;
    }
}
void displayCircularLL(struct Node*head){
    struct Node*p = head;
    if(p == NULL){
        printf("Linked List is Empty:\n");
    }else{
        int i = 0;
        while(p->next!=head){
            printf("Data at Node %d is %d\n",i,p->data);
            p = p->next;
            i++;
        }
        printf("Data at Node %d is %d\n",i,p->data);
    }
}
int main(){
    struct Node*head = NULL;
    int data;
    for(int i = 0; i<4;i++){
        printf("Enter the Data:\n");
        scanf("%d",&data);
        createLinkedList(&head,data);
    }
    printf("Linked List:\n");
    displayCircularLL(head);
}