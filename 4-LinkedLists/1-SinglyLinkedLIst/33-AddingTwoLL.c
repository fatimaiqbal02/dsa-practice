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
void reverseList(struct Node**head){
    struct Node*current = *head;
    struct Node*prevNode = NULL;
    struct Node*nextNode;
    while(current!=NULL){
        nextNode = current->link;
        current->link = prevNode;
        prevNode = current;
        current = nextNode;
    }
    *head = prevNode;
}
void addTwoLists(struct Node*head1, struct Node*head2){
    reverseList(&head1);
    reverseList(&head2);

    struct Node* p = head1;
    struct Node* q = head2;
    struct Node* head3 = NULL;

    while(p!=NULL && q!=NULL){
        int sum = p->data + q->data;
        int carry = sum/10;
        createNode(sum%10,&head3);
        
    }
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
    
    printf("Final Linked List After Merging:\n");
    displayLinkedList(&head1);
}
