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
void concatentateLists(struct Node *head1, struct Node *head2){
    struct Node*p = head1;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = head2;
    head2->prev = p;
}
void splitIntoEvenOdd(struct Node*head){
    struct Node*p = head;
    struct Node*even = NULL;
    struct Node*odd = NULL;
    struct Node *evenTail, *oddTail;

    while(p!=NULL){
        if(p->data %2 == 0){
            if(even == NULL){
                even = p;
                evenTail = p;
                evenTail->prev = NULL;
            }else{
                evenTail->next = p;
                p->prev = evenTail;
                evenTail = p;
            }
        }else if(p->data %2 != 0){
            if(odd == NULL){
                odd = p;
                oddTail = p;
                oddTail->prev = NULL;
            }else{
                oddTail->next = p;
                p->prev = oddTail;
                oddTail = p;
            }
        }
        p = p->next;
    }
    oddTail->next = NULL;
    evenTail->next = NULL;
    concatentateLists(even,odd);
    displayLinkedList(&even);
    
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
    
    printf("Double Link List After Splitting Into Even And Odd Nodes:\n");
    splitIntoEvenOdd(head1);
}