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
void deletingDuplicates(struct Node**head){
    struct Node*p = *head;
    struct Node*q;
    while(p->link!=NULL){
        if(p->data == p->link->data){
            q = p->link;
            p->link = q->link;
            free(q);
        }
           p = p->link; 
    }
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
    displayLinkedList(&head1);     //assume linked list is sorted

    printf("Linked List after deleting the duplicate values at Nodes:\n");
    deletingDuplicates(&head1);
    displayLinkedList(&head1); 
}
