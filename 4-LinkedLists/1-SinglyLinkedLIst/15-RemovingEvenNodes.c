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
void removeEvenNodes(struct Node **head){
    struct Node*p = *head;
    struct Node*q;
    struct Node*s;
    while(p!=NULL){
        if(p->data %2 == 0){
            if(p == *head){
                s = p;
                p = p->link;
                free(s);
                *head = p;
            }
            else{
                q->link = p->link;
                s = p;
                p = p->link;
                free(s);
            }
            
        }else{
            q = p;
            p = p->link;
        }
    }
 
}
int main(){
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    int noOfNodes;
    printf("Enter the No of Nodes for First Linked List: ");
    scanf("%d",&noOfNodes);
    for(int i = 0; i<noOfNodes; i++){
        createNode(&head1);
    }
    printf("First Linked List:\n");
    displayLinkedList(&head1);
   
    removeEvenNodes(&head1);
    printf("Linked Lists after deleting even Nodes:\n");
    printf("First Linked List:\n");
    displayLinkedList(&head1); 
 
}

