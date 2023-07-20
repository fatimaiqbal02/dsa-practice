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
}
void inorderTraversal(struct Node* root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d\t",root->data);
        inorderTraversal(root->right);
    }
}
void preOrderTraversal(struct Node*root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void postOrderTraversal(struct Node*root){
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d\t",root->data);
    }
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

    printf("\nPRE-ORDER traversal:\n");
    preOrderTraversal(root);

    printf("\nPOST-ORDER traversal:\n");
    postOrderTraversal(root);
}