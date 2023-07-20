#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
struct Node *head;
void createNode(int data){
    struct Node*ptr;
    if(head == NULL){
        struct Node* firstNode = (struct Node*)malloc(sizeof(struct Node)); 
        firstNode->data = data;
        firstNode->link = NULL;
        head = firstNode;
        ptr = head;
    }else{
        struct Node*nextNode = (struct Node*)malloc(sizeof(struct Node));
        nextNode->data = data;
        nextNode->link = NULL;
        ptr ->link = nextNode;
        ptr = nextNode;
    }
}
void displayLinkedList(struct Node**head){
    struct Node*p = *head;
    int i = 0;
    while(p!=NULL){
        printf("Data at Node %d = %d\n",i,p->data);
        p = p->link;
        i++;
    }
}
void breakListIntoTwoAtIndex(int index,struct Node **head2){
    struct Node*p = head;
    struct Node*q;
    for(int i = 0;i<index;i++){
        p = p->link;
    }
    q = p->link;
    p->link = NULL;
    *head2 = q;
}
int main(){
    struct Node*head2 = NULL;
    createNode(2);
    createNode(4);
    createNode(6);
    createNode(8);
    createNode(9);
    displayLinkedList(&head);
    breakListIntoTwoAtIndex(2,&head2);
    printf("First Linked List After Split:\n");
    displayLinkedList(&head);
    printf("Second Linked List After Split:\n");
    displayLinkedList(&head2);
}
