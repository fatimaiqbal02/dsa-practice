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
void pairWiseSwap(struct Node **head){
    struct Node *p = *head;
    struct Node *q = p->link;
    struct Node *s, *r;

    while(q!=NULL && q->link!=NULL){
        s = p->link->link;
        r = q->link->link;
        q->link = p;
        p->link = r;
        if(p == *head){
            *head = q;
        }else if(p->link == NULL){
            p->link = s;
            break;
        }
        p = s;
        q = r;
    }
    if(q->link == NULL){
        q->link = p;
        p->link = NULL;
    }
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

    printf("Final Linked List After Swapping the Data:\n");
    pairWiseSwap(&head1);
    displayLinkedList(&head1);

}