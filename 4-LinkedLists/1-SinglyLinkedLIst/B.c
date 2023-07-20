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
void displayLinkedList(struct Node **head){
    struct Node*p = *head;
    int i = 0;
    while(p!=NULL){
        printf("Data at Node %d = %d\n",i,p->data);
        p = p->link;
        i++;
    }
}
void splitOddEven(struct Node*head){
    struct Node*p = head;
    struct Node*odd = NULL;
    struct Node*even = NULL;
    struct Node* evenTail, *oddTail;

    while(p!=NULL){
        if(p->data %2 != 0){
            createNode(p->data,&even);
            p = p->link;
        }else if(p->data %2 == 0){
           createNode(p->data,&odd);
            p = p->link;
        }
    }

    printf("Odd Part:\n");
    displayLinkedList(&odd);
    printf("Even Part:\n");
    displayLinkedList(&even);
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
    displayLinkedList(&head1);;
    
    printf("Linked List After Moving Last Element to First:\n");
    splitOddEven(head1);
}