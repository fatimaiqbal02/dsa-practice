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
struct Node* reverseList(struct Node*head1,struct Node*finalHead){
    struct Node*current = head1;
    struct Node*prevNode = NULL;
    struct Node*nextNode;
    while(current!=NULL){
        nextNode = current->next;
        current->next = prevNode;
        current->prev = nextNode;
        prevNode = current;
        current = nextNode;
    }
    finalHead =prevNode;
    return finalHead;
}
int palindromeCheck(struct Node*head){
    int flag;
    struct Node*head2 = NULL;
    head2 = reverseList(head,head2);
    //displayLinkedList(&head2);
    struct Node* p = head;
    struct Node*q = head2;
    while(p!=NULL && q!=NULL){
        if(p->data == q->data){
            flag = 1;
            p = p->next;
            q = q->next;
        }else{
            flag = 0;
            break;
        }
    }
    return flag;
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
    
    if(palindromeCheck(head1)){
        printf("Sequence is A Palindrome:\n");
    }else{
        printf("Sequence is Not A Palindrome:\n");
    }
}