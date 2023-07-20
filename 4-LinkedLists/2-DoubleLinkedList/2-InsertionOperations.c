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
struct Node* insertAtFirst(int data, struct Node *head){
    struct Node*ptr =  (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;

    ptr->next = head;
    head->prev = ptr;
    head = ptr;
    
    return head;
}
void insertAtEnd(int data, struct Node **head){
    struct Node*ptr =  (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    struct Node*p = *head;
    while(p->next!= NULL){
        p = p->next;
    }
    ptr->prev = p;
    p->next = ptr;
}
void insertBeforeNode(int data, int index, struct Node **head){
    struct Node*ptr =  (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    
    struct Node*p = *head;
    struct Node*q;
    for(int i = 0; i<index-1; i++){
        p = p->next;
    }
    q = p->next;
    ptr->prev = p;
    p->next = ptr;
    ptr->next = q;
    q->prev = ptr;

}
void insertAfterNode(int data, int index, struct Node **head){
    struct Node*ptr =  (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    
    struct Node*p = *head;
    struct Node*q;
    for(int i = 0; i<index; i++){
        p = p->next;
    }
    q = p->next;
    ptr->prev = p;
    p->next = ptr;
    ptr->next = q;
    q->prev = ptr;
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

    /* printf("Double Link List After Insertion At First:\n");
    head1 = insertAtFirst(0,head1);
    displayLinkedList(&head1); */

    /* printf("Double Link List After Insertion At Last:\n");
    insertAtEnd(8,&head1);
    displayLinkedList(&head1); */

    /* printf("Double Link List After Insertion Before Node:\n");
    insertBeforeNode(8,2,&head1);
    displayLinkedList(&head1); */

    /* printf("Double Link List After Insertion Before Node:\n");
    insertAfterNode(5,2,&head1);
    displayLinkedList(&head1); */
}