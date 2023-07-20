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
void mergeTwoLists(struct Node*head1, struct Node*head2){
    struct Node*p =head1;
    struct Node*q = head2;
    struct Node *s ,*r;
    while(p->next!=NULL && q->next!=NULL){
        s = p->next;
        r = q->next;

        p->next = q;
        q->prev = p;

        q->next = s;
        s->prev = q;

        p = s;
        q = r;
    }
    if(p->next== NULL && q->next != NULL){
        p->next = q;
        q->prev = p;
        while(q->next != NULL){
            q = q->next;
        }
    }
    if(q->next==NULL && p->next != NULL){
        s = p->next;
        q->next = s;
        s->prev = q;

        p->next = q;
        q->prev = p;
        while(s->next!=NULL){
            s = s->next;
        }
    }
}
int main(){
    struct Node*head1 = NULL;
    struct Node*head2 = NULL;
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
     
    printf("Enter the No of Nodes for 2nd Linked List:\n");
    scanf("%d",&noOfNodes);

    for(int i = 0; i<noOfNodes;i++){
        printf("Enter the Data At Node:\n");
        scanf("%d",&data);
        createNode(data,&head2);
    }
    printf("Double Linked List:\n");
    displayLinkedList(&head2);


    printf("Double Link List After Merging Two Lists Alternatively:\n");
    mergeTwoLists(head1,head2);
    displayLinkedList(&head1);
}