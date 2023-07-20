#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
struct Node *head;
void createNode(){
    int data;
    struct Node*ptr;
    if(head == NULL){
        struct Node* firstNode = (struct Node*)malloc(sizeof(struct Node)); 
        printf("Enter the Data at Node: ");
        scanf("%d",&data);
        firstNode->data = data;
        firstNode->link = NULL;
        head = firstNode;
        ptr = head;
    }else{
        struct Node*nextNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the Data at Node: ");
        scanf("%d",&data);
        nextNode->data = data;
        nextNode->link = NULL;
        ptr ->link = nextNode;
        ptr = nextNode;
    }
}
void displayLinkedList(){
    struct Node*p = head;
    if(p == NULL){
        printf("Linked List is Empty:\n");
    }else{
        int i = 0;
        while(p!=NULL){
        printf("Data at Node %d = %d\n",i,p->data);
        p = p->link;
        i++;
    }
    }
    
}
void deleteAllNodes(){
    struct Node*p = head;
    struct Node*q;
    while(p!=NULL){
        q =p;
        p = p->link;
        head = p;
        free(q);
    }
}
int main(){
    int noOfNodes;
    printf("Enter the No of Nodes for Linked List: ");
    scanf("%d",&noOfNodes);

    for(int i = 0; i<noOfNodes; i++){
        createNode();
    }
    printf("First Linked List:\n");
    displayLinkedList();

     printf("Linked List after Deleting All the Nodes:\n");
    deleteAllNodes();
    displayLinkedList(); 
}
/* void deleteAllNodes(){
    struct Node*p = head;
    while(p->link!=NULL){
        p = p->link;
        free(p);
    }
    head = NULL;
    free(p);
} */