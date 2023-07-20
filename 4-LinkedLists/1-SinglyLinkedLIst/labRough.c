#include<stdio.h>
#include<stdlib.h>
struct Node{
    int coeff;
    int exp;
    struct Node* link;
}; 
struct Node*ptr;
void createNode(int coeff, int exp, struct Node**head){
    int data;
    if(*head == NULL){
        struct Node* firstNode = (struct Node*)malloc(sizeof(struct Node)); 
        firstNode->coeff = coeff;
        firstNode->exp = exp;
        firstNode->link = NULL;
        *head = ptr = firstNode;
    }else{
        struct Node*nextNode = (struct Node*)malloc(sizeof(struct Node));
        nextNode->coeff =coeff;
        nextNode->exp = exp;
        nextNode->link = NULL;
        ptr ->link = nextNode;
        ptr = nextNode;     
    }
}
void displayLinkedList(struct Node** head){
    struct Node*p = *head;
    if(p == NULL){
        printf("Linked List is Empty;\n");
    }else{
        int i = 0;
        while(p!=NULL){
            printf("%dx^%d ",p->coeff,p->exp);
            p = p->link;
            i++;
            if(p!=NULL){
                printf(" + ");
            }else{
                printf("\n");
            }
        }
    }
}

int main(){
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;
    int noOfNodes,coeff,exp;

    printf("Enter the No of Nodes for First Linked List: ");
    scanf("%d",&noOfNodes);

    for(int i = 0; i<noOfNodes; i++){
         printf("Enter the coefficiant and exponent: \n");
         scanf("%d %d",&coeff,&exp);
         createNode(coeff,exp,&head1);
    }
   
    printf("First Polynomial = ");
    displayLinkedList(&head1);

    printf("Enter the No of Nodes for Second Linked List: ");
    scanf("%d",&noOfNodes);

    for(int i = 0; i<noOfNodes; i++){
         printf("Enter the coefficiant and exponent: \n");
         scanf("%d %d",&coeff,&exp);
         createNode(coeff,exp,&head2);     
    }
   
    printf("Second Polynomial = ");
    displayLinkedList(&head2);

}