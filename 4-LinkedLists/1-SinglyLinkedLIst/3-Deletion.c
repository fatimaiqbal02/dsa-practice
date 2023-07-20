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
void deleteAtFirst(){
    struct Node*p = head;
    head = p->link;
    free(p);
}
void deleteAtEnd(){
    struct Node*p = head;
    struct Node*q = p->link;
    while(q->link!=NULL){
        p = p->link;
        q = q->link;
    }
    p->link = NULL;
    free(q);
}
void deleteBeforeNode(int index){
    struct Node*p = head;
    struct Node*q;
    for(int i = 0; i<index-2;i++){
        p = p->link;
    }
    q = p->link;
    p->link = q->link;
    free(q);
}
void deleteAfterNode(int index){
    struct Node*p = head;
    struct Node*q;
    for(int i = 0; i<index;i++){
        p = p->link;
    }
    q = p->link;
    p->link = q->link;
    free(q);
}
int main(){
    createNode(2);
    createNode(4);
    createNode(6);
    createNode(8);
    displayLinkedList();
    
    /* printf("After Deletion at First\n");
    deleteAtFirst();
    displayLinkedList(); */

    /* printf("After Deletion at Last\n");
    deleteAtEnd();
    displayLinkedList(); */

    /* printf("After Deletion Before Index\n");
    deleteBeforeNode(3);
    displayLinkedList(); */
    
    /* printf("After Deletion After Index\n");
    deleteAfterNode(1);
    displayLinkedList(); */

}
