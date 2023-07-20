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
struct Node* sortedMerge(struct Node *head1, struct Node *head2, struct Node*head3){
    struct Node *p = head1;
    struct Node*q = head2;
    while(p!=NULL && q!=NULL){
        if(p->data == q->data){
            createNode(p->data,&head3);
            q = q->link;
            p = p->link;
        }
        else if(p->data < q->data){
            createNode(p->data,&head3);
            p = p->link;
        }else if(q->data < p->data){
            createNode(q->data,&head3);
            q = q->link;
        }
    }
    if(p == NULL && q!= NULL){
        while(q!=NULL){
            createNode(q->data,&head3);
            q = q->link;
        }
    } 

    if(q == NULL && p!= NULL){
        while(p!=NULL){
            createNode(p->data,&head3);
            p = p->link;
        }
    }

    //displayLinkedList(&head3); 
    return head3;
}

int main(){
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;
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

    printf("Enter the No of Nodes for Second Linked List: ");
    scanf("%d",&noOfNodes);
    for(int i = 0; i<noOfNodes; i++){
        printf("Enter the Data :\n");
        scanf("%d",&data);
        createNode(data, &head2);
    }
    printf("Second Linked List:\n");
    displayLinkedList(&head2);
    
    printf("Final Linked List After Sortion:\n");
    head3 = sortedMerge(head1,head2,head3);
    displayLinkedList(&head3);

}
