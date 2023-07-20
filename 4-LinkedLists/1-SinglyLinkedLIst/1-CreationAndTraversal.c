#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
struct Node* head;
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
int main(){
    createNode(2);
    createNode(4);
    createNode(6);
    displayLinkedList();
}
