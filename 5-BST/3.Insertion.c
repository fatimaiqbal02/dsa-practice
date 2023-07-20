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
void insertion(struct Node*root,int data){
    struct Node*prev = NULL;
    struct Node*ptr = createNode(data);
    while(root!=NULL){
        prev = root;
        if(root->data == data){
            printf("Duplicate Entry:\nCannot be Inserted:\n");
            return;
        }else if(root->data > data){
            root = root->left;
        }else if(root->data < data){
            root = root->right;
        }
    }
    if(prev->data < data){
        prev->right = ptr;
    }else{
        prev->left = ptr;
    }
}
void inorderTraversal(struct Node* root){
    if(root!=NULL){
        inorderTraversal(root->left);
        printf("%d\t",root->data);
        inorderTraversal(root->right);
    }
}
int main(){
    struct Node* root = createNode(5);
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
    
    printf("IN-ORDER traversal Before Insertion:\n");
    inorderTraversal(root);
    
    insertion(root,5);
    printf("\nIN-ORDER traversal After 1st Insertion:\n");
    inorderTraversal(root);

    insertion(root,4);
    printf("\nIN-ORDER traversal After 2nd Insertion:\n");
    inorderTraversal(root);
}