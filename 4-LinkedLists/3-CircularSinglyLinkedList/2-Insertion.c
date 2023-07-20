#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
void createLinkedList(struct Node **head){
    struct Node*ptr;
    int data;
    printf("Enter the Data:\n");
    scanf("%d",&data);
    if(*head == NULL){
        struct Node*firstNode = (struct Node*)malloc(sizeof(struct Node));
        firstNode->data = data;
        firstNode->next = firstNode;
        *head = ptr = firstNode;
    }else{
        struct Node*newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = *head;
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
struct Node*insertAtFirst(struct Node*head,int data){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node*p = head;
    while(p->next!=head){
        p = p->next;
    }
    ptr->next = head;
    head = ptr;
    p->next = head;
    return head;
}
void insertAtEnd(struct Node*head, int data){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node*p = head;
    while(p->next!=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
}
void insertAfterNode(struct Node*head, int data,int index){
    int i = 0;
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node*p = head;
    while(i!=index){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
}
void insertBeforeNode(struct Node*head, int data,int index){
     int i = 0;
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node*p = head;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
}
int main(){
    struct Node*head = NULL;
    for(int i = 0; i<4;i++){
        createLinkedList(&head);
    }
    printf("Linked List:\n");
    displayCircularLL(head);

   /*  head = insertAtFirst(head,0);
    printf("Linked List After Insertion At First:\n");
    displayCircularLL(head); */
    
    /* insertAtEnd(head,10);
    printf("Linked List After Insertion At End:\n");
    displayCircularLL(head); */
   
/*  insertAfterNode(head,5,1);
    printf("Linked List After Insertion After Node:\n");
    displayCircularLL(head); */
    
/*     insertBeforeNode(head,5,2);
    printf("Linked List After Insertion After Node:\n");
    displayCircularLL(head); */
    
}