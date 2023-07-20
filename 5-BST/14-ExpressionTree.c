#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    char data;
    struct Node*right;
    struct Node*left;
    struct Node*next;
};
struct Node* head = NULL;
struct Node* createNode(char data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->right = NULL;
    ptr->left = NULL;
    ptr->next = NULL;
    return ptr;
}
void printInOrderTraversal(struct Node* root){
    if(root!=NULL){
        printInOrderTraversal(root->left);
        printf("%c\t",root->data);
        printInOrderTraversal(root->right);
    }
}
int isEmpty(){
    if(head == NULL){
        return 1;
    }
    return 0;
}
int isFull(){
     struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
     if(ptr == NULL){
         return 1;
     }
     return 0;
}
void push(struct Node* p){
    if(isFull()){
        printf("Cannot be pushed:\nStack overflow\n");
    }else{
        if(head == NULL){
          head = p;
        }else{
            p->next = head;
            head = p;
        }
        printf("Node with Data %c is pushed into Stack:\n",p->data);
    }
}
struct Node* pop(){
    struct Node*p = head;
    head = head->next;
    printf("Node with Data %c is removed from Stack:\n",p->data);
    return p;
}
void ConstructExpTree(char postfix[]){
    struct Node*s,*r,*l;
    for(int i = 0; i<strlen(postfix); i++){
        if(postfix[i] == '+' ||postfix[i] == '-' ||postfix[i] == '*' ||postfix[i] == '/'){
            s = createNode(postfix[i]);
            r = pop();
            l = pop();
            s->right = r;
            s->left = l;
            push(s);
        }else{
           s = createNode(postfix[i]);
           push(s);
        }
    }
    printf("Inorder Traversal:");
    printInOrderTraversal(s);
}
int main(){
    char postfix[] = "ab*c/ef/g*+k+xy*-";
    ConstructExpTree(postfix);
}