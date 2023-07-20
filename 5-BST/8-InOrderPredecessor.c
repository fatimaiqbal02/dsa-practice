#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node*right;
    struct Node*left;
};
struct Node*root = NULL;
struct Node*createNode(int data){
    struct Node*ptr = (struct Node*) malloc(sizeof(struct Node));
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
        struct Node*p = root;
        while(p!=NULL){
            prev = p;
            if(p->data == data){
                printf("Duplicate Entry:\nCannot be Inserted:\n");
                return;
            }else if(p->data > data){
               p = p->left;
            }else if(p->data < data){
                p = p->right;
            }
        }
        if(prev->data > data){
            prev->left = ptr;
        }else{
            prev->right = ptr;
        }
    }
}
void inorderTraversal(struct Node*root){
    struct Node*p = root;
    if(p!=NULL){
        inorderTraversal(p->left);
        printf("%d\t",p->data);
        inorderTraversal(p->right);
    }
}
struct Node* inOrderPredecessor(struct Node* root,int key){
    struct Node*p = root;
    if(p == NULL){
        return NULL;
    }else{
        while(p!=NULL){
        if(p->data == key){
            if(p->left != NULL){
                p = p->left;
                while(p->right!=NULL){
                    p = p->right;
                }
            return p;
            }else{
                return NULL;
            }
        }
        else if(p->data > key){
            p = p->left;
        }
        else if(p->data < key){
            struct Node*pred = p;
            p = p->right;
            return pred;
        }
       }
    }
}
int main(){
    int data;
    for(int i = 0; i<7; i++){
        printf("Enter the Data:\n");
        scanf("%d",&data);
        createTree(data);
    }
    
    printf("IN-ORDER traversal:\n");
    inorderTraversal(root);
    int d = 10;
    struct Node* p  = inOrderPredecessor(root,d); 
    if(p!=NULL){
        printf("\nInOrder Predecessor of %d is %d\n",d, p->data); 
    }else{
        printf("\nInOrder Predecessor of %d  does not Exists:\n",d); 
    }
    
}