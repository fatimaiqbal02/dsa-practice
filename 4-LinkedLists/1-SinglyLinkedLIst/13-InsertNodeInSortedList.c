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

void displayLinkedList(struct Node **head){
    struct Node*p = *head;
    int i = 0;
    while(p!=NULL){
        printf("Data at Node %d = %d\n",i,p->data);
        p = p->link;
        i++;
    }
}
void insertSortedNode(int data, struct Node **head){    //insert before node
    struct Node*ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = *head;
    struct Node *q;
    while(p!=NULL){
        if(p->data >= ptr->data){
            ptr->link = p;
            q->link = ptr;
            break;
        }
        q = p;
        p = p->link;
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

    printf("Linked List after Sorting All the values at Nodes:\n");
    insertSortedNode(4,&head1);
    displayLinkedList(&head1); 
}
