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
void splitOddEven(struct Node*head){
    struct Node*p = head;
    struct Node*odd = NULL;
    struct Node*even = NULL;
    struct Node* evenTail, *oddTail;

    while(p!=NULL){
        if(p->data %2 != 0){
            if(odd == NULL){
                odd = p;
                oddTail = p;
            }else{
                oddTail->link = p;
                oddTail = p;
            }
            p = p->link;
        }else if(p->data %2 == 0){
            if(even == NULL){
                even = p;
                evenTail = p;
            }else{
                evenTail->link = p;
                evenTail = p;
            }
            p = p->link;
        }
    }
    evenTail->link = NULL;
    oddTail->link = NULL;

    p = head = even;
    while(p->link!=NULL){
        p = p->link;
    }
    p->link = odd;
    displayLinkedList(&head);
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
    
    printf("Linked List After Moving Last Element to First:\n");
    splitOddEven(head1);
}