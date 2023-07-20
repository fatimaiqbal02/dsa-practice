#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
};
void createNode(int data, struct Node **head){
    struct Node*ptr;
    if(*head == NULL){
        struct Node* firstNode = (struct Node*) malloc(sizeof(struct Node));
        firstNode->data = data;
        firstNode->prev = NULL;
        firstNode->next = NULL;
        ptr = *head = firstNode;
    }else{
        struct Node* nextNode = (struct Node*) malloc(sizeof(struct Node));
        nextNode->data = data;
        nextNode->next = NULL;
        
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }

        nextNode->prev = ptr;
        ptr->next = nextNode;

        ptr = nextNode;
    }
}
void displayLinkedList(struct Node **head){
    struct Node*p = *head;
    int i = 0;
    if(p == NULL){
        printf("The Linked List Is Empty:\n");
    }else{
        while(p!=NULL){
            printf("Data at Node %d = %d\n",i,p->data);
            p = p->next;
            i++;
        }
    }
}
void sortingList(struct Node *head){
    int temp;
    struct Node*p =head;
    struct Node*q;
    while(p->next!=NULL){
        q = p->next;
        while(q->next!=NULL){
            if(p->data >= q->data){
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
              q = q->next;
        }
        p = p->next;
    }
    
}
int main(){
    struct Node*head1 = NULL;
    int noOfNodes,data;
    printf("Enter the No of Nodes for Linked List:\n");
    scanf("%d",&noOfNodes);

    for(int i = 0; i<noOfNodes;i++){
        printf("Enter the Data At Node:\n");
        scanf("%d",&data);
        createNode(data,&head1);
    }
    printf("Double Linked List:\n");
    displayLinkedList(&head1);
    
    printf("Double Link List After Sorting Values In  Nodes:\n");
    sortingList(head1);
    displayLinkedList(&head1);
}