#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*right;
    struct Node*left;
};
struct Node*createNode(int data){
    struct Node*ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;
}
void inorderTraversal(struct Node* root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d\t",root->data);
        inorderTraversal(root->right);
    }
}
void search(struct Node* root, int data){
    while(root!=NULL){
        if(root->data == data){
            printf("\nKey Found Succesfully:\n");
            return;
        }else if(root->data > data){
            root = root->left;
        }else if(root->data < data){
            root = root->right;
        }
    }
    printf("\nKey Not Found:\n");
}
int main(){
    struct Node* root = createNode(4);
    struct Node* l = createNode(3);
    struct Node* r = createNode(5);
    struct Node* r_r = createNode(6);
    struct Node* l_l = createNode(1);
    struct Node* l_l_r = createNode(2);

    root->left = l;
    root->right = r;
    r->right = r_r;
    l->left = l_l;
    l_l->right = l_l_r;
    
    printf("IN-ORDER traversal:\n");
    inorderTraversal(root);

    search(root,2);
}