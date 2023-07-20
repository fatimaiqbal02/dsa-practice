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
struct Node* deleteAtFirst(struct Node*head){
    struct Node*p = head;
    struct Node*q = head;
    while(p->next!=head){
        p = p->next;
    }
    head = head->next;
    p->next = head;
    free(q);
    return head;
}
void deleteAtEnd(struct Node*head){
    struct Node*p = head;
    struct Node*q;
    while(p->next!=head){
        q = p;
        p = p->next;
    }
    q->next = head;
    free(p);
}
void deleteAfterNode(struct Node*head, int index){
    struct Node*p = head;
    struct Node*q;
    int i = 0;
    while(i!=index+1){
        q = p;
        p = p->next;
        i++;
    }
    q->next = p->next;
    free(p);
}
void deleteBeforeNode(struct Node*head, int index){
    struct Node*p = head;
    struct Node*q;
    int i = 0;
    while(i!=index-1){
        q = p;
        p = p->next;
        i++;
    }
    q->next = p->next;
    free(p);
}
int main(){
    struct Node*head = NULL;
    for(int i = 0; i<4;i++){
        createLinkedList(&head);
    }
    printf("Linked List:\n");
    displayCircularLL(head);

    /* head =deleteAtFirst(head);
    printf("Linked List After Deletion At First:\n");
    displayCircularLL(head); */
   
    /* deleteAtEnd(head);
    printf("Linked List After Deletion At End:\n");
    displayCircularLL(head);  */

    /* deleteAfterNode(head,1);
    printf("Linked List After Deletion After Node:\n");
    displayCircularLL(head); */

   /*  deleteBeforeNode(head,2);
    printf("Linked List After Deletion Before Node:\n");
    displayCircularLL(head); */
}