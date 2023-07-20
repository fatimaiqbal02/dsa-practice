#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
void createNode(int data, struct Node**head){
    struct Node*ptr;
    if(*head == NULL){
        struct Node* firstNode = (struct Node*)malloc(sizeof(struct Node)); 
        firstNode->data = data;
        firstNode->link = NULL;
        *head = ptr = firstNode;
    }else{
        struct Node*nextNode = (struct Node*)malloc(sizeof(struct Node));
        nextNode->data = data;
        nextNode->link = NULL;
        while(ptr->link!=NULL){
            ptr = ptr->link;
        }
        ptr ->link = nextNode;
        ptr = nextNode;
    }
}
void displayLinkedList(struct Node** head){
    struct Node*p = *head;
    int i = 0;
    while(p!=NULL){
        printf("Data at Node %d = %d\n",i,p->data);
        p = p->link;
        i++;
    }
}
void splitInTwoLists(struct Node *head1){
    struct Node*p = head1;
    struct Node*head2 = p->link;
    struct Node*q = head2;
    while(q!=NULL  &&q->link!=NULL){
        p->link = p->link->link;
        q->link = q->link->link;
        p = p->link;
        q = q->link;
    }
    if(q!=NULL && q->link == NULL){    //for odd ll
        p->link = NULL;
    }
    printf("First Linked List:\n");
    displayLinkedList(&head1);

    printf("Second Linked List:\n");
    displayLinkedList(&head2); 

}


int main(){
    struct Node *head1 = NULL;
    int noOfNodes, data;
    printf("Enter the No of Nodes for First Linked List: ");
    scanf("%d",&noOfNodes);
    for(int i = 0; i<noOfNodes; i++){
        printf("Enter the Data :\n");
        scanf("%d",&data);
        createNode(data, &head1);
    }
    printf("First Linked List:\n");
    displayLinkedList(&head1);

    printf("After Splitting:\n");
    splitInTwoLists(head1);
    
}
  