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
void displayLinkedList(){
    struct Node*p = head;
    int i = 0;
    while(p!=NULL){
        printf("Data at Node %d = %d\n",i,p->data);
        p = p->link;
        i++;
    }
}
void insertAtFirst(int data){
    struct Node*ptr =  (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->link = head;
    head = ptr;
}
void insertAtEnd(int data){
    struct Node*p = head;
    struct Node*ptr =  (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->link = NULL;
    while(p->link!=NULL){
        p = p->link;
    }
    p->link = ptr;
}
void insertBeforeNode(int index,int data){
    struct Node*p = head;
    struct Node*ptr =  (struct Node*)malloc(sizeof(struct Node));
    for(int i = 0; i<index-1;i++){
        p = p->link;
    }
    ptr->data = data;
    ptr->link = p->link;
    p->link = ptr;
}
void insertAfterNode(int index, int data){
    struct Node*p = head;
    struct Node*ptr =  (struct Node*)malloc(sizeof(struct Node));
    for(int i = 0; i<index;i++){
        p = p->link;
    }
    ptr->data = data;
    ptr->link = p->link;
    p->link = ptr;
}
int main(){

    createNode(2);
    createNode(4);
    createNode(6);
    createNode(8);
    displayLinkedList();

    /* printf("After insertion at First\n");
    insertAtFirst(0);
    displayLinkedList(); */

    /* printf("After insertion at Last\n");
    insertAtEnd(10);
    displayLinkedList(); */

    /* printf("After insertion Before Node\n");
    insertBeforeNode(2,5);
    displayLinkedList(); */
    
    /* printf("After insertion After Node\n");
    insertAfterNode(1,5);
    displayLinkedList(); */

}
