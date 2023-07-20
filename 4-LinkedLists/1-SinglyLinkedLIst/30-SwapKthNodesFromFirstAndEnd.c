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
void swapKthNodes(int index, int noOfNodes, struct Node **head){
    struct Node*p = *head;
    struct Node*q = *head;
    struct Node *s, *r;
    for(int i = 0; i<index-1; i++){
        s = p;
        p = p->link;
    }

    for(int i = 0; i< noOfNodes-(index-1); i++){
        r = q;
        q = q->link;
    }
    printf("%d\n",q->data);

    p->link = q->link; 
    r->link = p;
    s->link = q;
    q->link = r;  
}
int main(){
    struct Node *head1 = NULL;
    int noOfNodes, data, index;
    printf("Enter the No of Nodes for First Linked List: ");
    scanf("%d",&noOfNodes);
    for(int i = 0; i<noOfNodes; i++){
        printf("Enter the Data :\n");
        scanf("%d",&data);
        createNode(data, &head1);
    }
    printf("First Linked List:\n");
    displayLinkedList(&head1);
    
    printf("Enter the No Node to be Swapped from Both sides:\n");
    scanf("%d",&index);
    swapKthNodes(index,noOfNodes,&head1);

    printf("Final Linked List After Swapping the Kth Nodes:\n");
    displayLinkedList(&head1);

}