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
void sortingLinkedList(struct Node **head){
    int temp;
    struct Node* p = *head;
    struct Node*q;
    while(p->link!= NULL){
        q = p->link;
        while(q!=NULL){
            if(p->data > q->data){
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->link;
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
    displayLinkedList(&head1);

    printf("Linked List after Sorting All the values at Nodes:\n");
    sortingLinkedList(&head1);
    displayLinkedList(&head1); 
}
