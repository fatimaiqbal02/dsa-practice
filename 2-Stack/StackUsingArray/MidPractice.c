#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*prev;
    struct Node*next;
};
void createNode(int data,struct Node**head){
    struct Node*ptr;
    if(*head == NULL){
        struct Node* firstNode = (struct Node*) malloc(sizeof(struct Node));
        firstNode->data = data;
        firstNode->prev = NULL;
        firstNode->next = NULL;
        *head = ptr = firstNode;
    }else{
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->prev = ptr;
        newNode->next = NULL;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = newNode;
        ptr = newNode;
    }
}
void displayLinkedList(struct Node**head){
    struct Node*p = *head;
    int i = 0;
    while(p!=NULL){
        printf("Data at Node %d is %d\n",i,p->data);
        p = p->next;
        i++;
    }
}
struct Node* splitIntoTwo(struct Node**head,int noOfNodes){
    struct Node *p = *head;
    struct Node *q;
    struct Node *head2 = NULL;
    int i = 0;
    while(i != noOfNodes/2){
        q = p;
        p = p->next;
        i++;
    }
    q->next = NULL;
    head2 = p;
    return head2;
}
int isEmpty(struct Node *top){
    if(top == NULL){
        return 1;
    }return 0;
}
int isFull(){
    struct Node*ptr =  (struct Node*) malloc(sizeof(struct Node));
    if(ptr == NULL){
        return 1;
    }return 0;
}
void push(int value, struct Node **top){
    if(isFull()){
        printf("Push Operation Not possible:\n");
    }else{
         struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
         newNode->data = value;
         newNode->next = *top;
         newNode->prev = NULL;
         *top = newNode;
         printf("%d is pushed into stack:\n",value);
    }
}
int pop(struct Node **top){
    int value;
    if(isEmpty(*top)){
        printf("Pop Operation Not possible:\n");
    }else{
        struct Node *p = *top;
        value = p->data;
        *top = p->next;
        p->next->prev = NULL;
        free(p);
        printf("%d is popped out of stack:\n",value);
    }
    return value;
}
int main(){
    struct Node*head1 = NULL;
    int top = -1;
    struct Node*head2 = NULL;
    int noOfNodes,data;
    
    printf("Enter the no of Nodes you want to make:\n");
    scanf("%d",&noOfNodes);
    for (int i = 0; i < noOfNodes;i++)
    {
       printf("Enter the data:\n");
       scanf("%d",&data);
       createNode(data,&head1);
    }
    printf("First Linked List:\n");
    displayLinkedList(&head1);
    printf("After splitting into two:\n");
    head2 = splitIntoTwo(&head1,noOfNodes);

    printf("First Linked List:\n");
    displayLinkedList(&head1);

    printf("Second Linked List:\n");
    displayLinkedList(&head2);
    
    push(2,&head2);
    push(3,&head2);
    push(4,&head2);
    pop(&head2);

    printf("Second Linked List:\n");
    displayLinkedList(&head2);
}
