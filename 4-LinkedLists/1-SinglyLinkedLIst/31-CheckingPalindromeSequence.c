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
struct Node* reverseList(struct Node*head,struct Node*finalHead){
    struct Node*current = head;
    struct Node*prev = NULL;
    struct Node*nextNode;
    while(current!=NULL){
        nextNode = current->link;
        current->link = prev;
        prev = current;
        current = nextNode;
    }
    finalHead = prev;
    
    return finalHead;
}
int palindromeSequenceCheck(struct Node*head){
    int flag;
    struct Node*p = head;
    struct Node*head2 = NULL;
    head2 = reverseList(head,head2);
    //displayLinkedList(&head2);
    struct Node*q = head2;
    while(p!=NULL && q!=NULL){
        if(p->data == q->data){
            flag = 1;
            p = p->link;
            q = q->link;
        }else{
            flag = 0;
            break;
        }
    }
    return flag;
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

    //printf("Final Linked List :\n");
   // palindromeSequenceCheck(head1);
    if(palindromeSequenceCheck(head1)){
        printf("Sequence is A Palindrome:\n");
    }else{
        printf("Sequence is Not A Palindrome:\n");

    }
}