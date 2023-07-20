#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
void createNode(struct Node **head){
    struct Node*ptr;
    int data;
    if(*head == NULL){
        struct Node* firstNode = (struct Node*)malloc(sizeof(struct Node)); 
        printf("Enter the data:\n");
        scanf("%d",&data);
        firstNode->data = data;
        firstNode->link = NULL;
        *head = ptr = firstNode;
    }else{
        struct Node*nextNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data:\n");
        scanf("%d",&data);
        nextNode->data = data;
        nextNode->link = NULL;
        ptr ->link = nextNode;
        ptr = nextNode;
    }
}
void reverseList(struct Node**head){
    struct Node *currentNode = *head;
    struct Node *prevNode = NULL;
    struct Node *nextNode;
    while(currentNode!= NULL){
        nextNode = currentNode->link;
        currentNode->link = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    *head = prevNode;
}
void findDataAtKthNode(int index, struct Node**head){
    struct Node*p = *head;
    for(int i = 0; i < index; i++){
        p = p->link;
    }
    printf("Data at %dth node = %d\n",index,p->data);
}
void displayLinkedList(struct Node **head){
    struct Node*p = *head;
    int i = 0;
    while(p!=NULL){
        printf("Data at Node %d = %d\n",i,p->data);
        p = p->link;
        i++;
    }
}
int main(){
    struct Node *head1 = NULL;
    int noOfNodes;
    printf("Enter the No of Nodes for Linked List: ");
    scanf("%d",&noOfNodes);

    for(int i = 0; i<noOfNodes; i++){
        createNode(&head1);
    }
    printf("Linked List:\n");
    displayLinkedList(&head1);
    
    reverseList(&head1);
    findDataAtKthNode(2,&head1);
}