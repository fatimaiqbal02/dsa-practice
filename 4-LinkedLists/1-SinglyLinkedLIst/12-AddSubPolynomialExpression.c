#include<stdio.h>
#include<stdlib.h>
struct Node{
    int coeff;
    int exp;
    struct Node* link;
}; 
void createNode(int coeff, int exp, struct Node**head){
    struct Node*ptr;
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
        while(ptr->link!=NULL){      //as *ptr is pointing to head here..
            ptr = ptr->link;
        }
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
void sortingList(struct Node **head){             //In case if user enter polynomials with degrees un-arramged
    int temp, temp2;
    struct Node*p  = *head;
    struct Node*q;
    while(p!=NULL){
        q = p->link;
        while(q!=NULL){
            if(p->exp < q->exp){
                temp = p->exp;
                p->exp = q->exp;
                q->exp = temp;

                temp2 = p->coeff;
                p->coeff = q->coeff;
                q->coeff = temp2;
            }
            q = q->link;
        }
        p = p->link;
    }
}

void addSubtractPolynomials(int choice, struct Node *head1, struct Node *head2, struct Node *head3){
    struct Node*p = head1;
    struct Node*q = head2;
    while(p!= NULL && q!= NULL){
        if(p->exp == q->exp){
            if(choice == 1){           //in case of subtraction
                 createNode(p->coeff + q->coeff , p->exp , &head3);
                 p = p->link;
                 q = q->link;
            }else if(choice == 2){     //in case of addition
                 createNode(p->coeff - q->coeff , p->exp , &head3);
                 p = p->link;
                 q = q->link;
            }
        }else if(p->exp > q->exp){
            createNode(p->coeff , p->exp , &head3);
            p = p->link;
        }else if(p->exp < q->exp){
            createNode(q->coeff , q->exp , &head3);
            q = q->link;
        }   
    }
    if(q == NULL && p!=NULL){
        while(p!= NULL){
            createNode(p->coeff , p->exp , &head3);
            p = p->link;
        }
    }else if(p == NULL && q!= NULL){
        while(q!= NULL){
            createNode(q->coeff , q->exp , &head3);
            q = q->link;
        }
    }
    displayLinkedList(&head3);
}
     
int main(){
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;
    struct Node *head3 = NULL;
    int choice, noOfNodes, coeff, exp;

    printf("Enter the No of Nodes for First Linked List: ");
    scanf("%d",&noOfNodes);

    for(int i = 0; i<noOfNodes; i++){
        printf("Enter the coefficiant and exponent: \n");
        scanf("%d %d",&coeff,&exp);
        createNode(coeff,exp,&head1);
    }
    
    sortingList(&head1);
    printf("First Polynomial = ");
    displayLinkedList(&head1);

    printf("Enter the No of Nodes for Second Linked List: ");
    scanf("%d",&noOfNodes);

    for(int i = 0; i<noOfNodes; i++){
        printf("Enter the coefficiant and exponent :\n");
        scanf("%d %d",&coeff,&exp);
        createNode(coeff,exp,&head2);     
    }

    sortingList(&head2);
    printf("Second Polynomial = ");
    displayLinkedList(&head2);

 
    do{
        printf("======= MENU ========\n");
        printf("1- Add Two Polynomials:\n");
        printf("2- Subtract Two Polynomials:\n");
        printf("3- Exit:\n");
        printf("Select Your Option;\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Polynomial after Addition  = ");
                addSubtractPolynomials(choice,head1,head2,head3);
            break;  

            case 2:
                printf("Polynomial After Subtraction = ");
                addSubtractPolynomials(choice,head1,head2,head3);
            break;

            case 3:
            break;

            default:
                printf("Select Right Option:\n");
            break;
        }
        }while(choice != 3);
        printf("----------------------\n");

}