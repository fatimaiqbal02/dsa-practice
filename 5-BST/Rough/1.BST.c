#include<stdio.h>
struct Node{
    int data;
    struct Node*right;
    struct Node*left;
};
struct Node*root = NULL;
struct Node*createNode(int data){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;
}
void createTree(int data){
  if(root == NULL){
      root = createNode(data);
  }else{
    struct Node*prev = NULL;
    struct Node*ptr = createNode(data);
    while(root!=NULL){
        prev = root;
        if(data < root->data){
            root = root->left;
        }else if(data > root->data){
            root = root->right;
        }else if(data == root->data){
            printf("Cannot be inserted:\nDuplicate Value:\n");
            return;
        }
    }
    if(data < prev->data){
        prev->left = ptr;
    }else{
        prev->right = ptr;
    }
  }
}
void insert(int data){
    struct Node*prev = NULL;
    struct Node*ptr = createNode(data);
    while(root!=NULL){
        prev = root;
        if(data < root->data){
            root = root->left;
        }else if(data > root->data){
            root = root->right;
        }else if(data == root->data){
            printf("Cannot be inserted:\nDuplicate Value:\n");
            return;
        }
    }
    if(data < prev->data){
        prev->left = ptr;
    }else{
        prev->right = ptr;
    }
}
struct Node* delete(){}
void search(){}
void preOrderTraversal(){}
void inOrderTraversal(){}
void postOrderTraversal(){}
int main(){

}