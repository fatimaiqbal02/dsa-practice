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
struct Node *inOrderPredecessor(struct Node*root){
    struct Node*p = root;
    p = p->left;
    while(p->right!=NULL){
        p = p->right;
    }
    return p;
}
struct Node* deletion(struct Node*root,int data){
    if(root == NULL){
       return NULL;
    }if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }if(root->data > data){
        root->left = deletion(root->left,data);
    }else if(root->data < data){
        root->right = deletion(root->right,data);
    }else{
        struct Node*iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deletion(root->left,iPre->data);
    }
    return root;
}
void inorderTraversal(struct Node* root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d\t",root->data);
        inorderTraversal(root->right);
    }
}
int main(){
    struct Node* root = createNode(6);
    struct Node* l = createNode(3);
    struct Node* r = createNode(7);
    struct Node* r_r = createNode(8);
    struct Node* l_l = createNode(1);
    struct Node* l_l_r = createNode(2);

    root->left = l;
    root->right = r;
    r->right = r_r;
    l->left = l_l;
    l_l->right = l_l_r;
    
    printf("IN-ORDER traversal Before  Deletion:\n");
    inorderTraversal(root);
    
    deletion(root,2);
    printf("\nIN-ORDER traversal After Deletion:\n");
    inorderTraversal(root);

}