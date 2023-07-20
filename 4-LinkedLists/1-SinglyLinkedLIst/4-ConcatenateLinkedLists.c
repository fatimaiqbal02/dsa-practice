#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* link;
};
void createNode(struct Node**head){
    struct Node*ptr;
    int data;
    if(*head == NULL){
        struct Node* firstNode = (struct Node*)malloc(sizeof(struct Node)); 
        printf("Enter the data at Node: ");
        scanf("%d",&data);
        firstNode->data = data;
        firstNode->link = NULL;
        *head = ptr = firstNode;
    }else{
        struct Node*nextNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data at Node: ");
        scanf("%d",&data);
        nextNode->data = data;
        nextNode->link = NULL;
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
void concatenateLinkedLists(struct Node *head1,struct Node *head2,struct Node *head3){
    struct Node *p = head1;
    while(p->link!= NULL){
        p = p->link;
    }
    p->link = head2;

    struct Node *ptr = head2;
    while(ptr->link!= NULL){
        ptr = ptr->link;
    }
    ptr->link = head3;
}
int main(){
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;
    int noOfNodes;
    printf("Enter the No of Nodes for First Linked List: ");
    scanf("%d",&noOfNodes);
    for(int i = 0; i<noOfNodes; i++){
        createNode(&head1);
    }
    printf("First Linked List:\n");
    displayLinkedList(&head1);

    printf("Enter the No of Nodes for Second Linked List: ");
    scanf("%d",&noOfNodes);
    for(int i = 0; i<noOfNodes; i++){
        createNode(&head2);
    }
    printf("Second Linked List:\n");
    displayLinkedList(&head2);

    printf("Enter the No of Nodes for Third Linked List: ");
    scanf("%d",&noOfNodes);
    for(int i = 0; i<noOfNodes; i++){ 
        createNode(&head3);
    }
    printf("Second Linked List:\n");
    displayLinkedList(&head3);
    
    printf("Final Linked List After Concatenation:\n");
    concatenateLinkedLists(head1,head2,head3);
    displayLinkedList(&head1);

}
