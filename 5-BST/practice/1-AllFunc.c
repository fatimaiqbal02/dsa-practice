#include<stdio.h>
struct Node{
    int data;
    struct Node*left;
    struct Node*right;
};
struct Node*root = NULL;
void InorderTraversal(struct Node*root){
    while(root!=NULL){
        InorderTraversal(root->left);
        printf("%d\t,root->data");
        InorderTraversal(root->right);
    }
}
struct Node* createNode(int data){
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->right = NULL;
    ptr->left = NULL;
}
void createTree(int data){
    if(root == NULL){
        root = createNode(data);
    }else{
        struct Node*p = root;
        struct Node*prev = NULL;
        while(p!=NULL){
            prev = p;
            if(p->data == data){
                printf("Cannot Enter: Already Present:\n");
                return;
            }
            else if(data < p->data){
                p = p->left;
            }else if(data > p->data){
                p = p->right;
            }
        }
        if(data < prev->data){
            prev->left = createNode(data);
        }
        else
            prev->right = createNode(data);
        }
}
void insert(int data){
    struct Node*p = root;
    struct Node*prev = NULL;
    while(p!=NULL){
        prev = p;
        if(p->data == data){
            printf("Cannot Enter: Already Present:\n");
            return;
        }
        else if(data < p->data){
            p = p->left;
        }else if(data > p->data){
            p = p->right;
        }
    }
    if(data < prev->data){
        prev->left = createNode(data);
    }
    else
        prev->right = createNode(data);
}
struct Node* InorderPredcessor(struct Node*root){
    struct Node*p = root;
    p = p->left;
    while(p->right!=NULL){
        p = p->right;
    }
    return p;
}
struct Node* delete(struct Node*root, int data){
    if(root==NULL){
        return NULL;
    }else if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }else if(data > root->data){
        root->right = delete(root->right, data);
    }else if(data < root->data){
        root->left = delete(root->left, data);
    }else{
        struct Node *ipre = InorderPredcessor(root);
        root->data = ipre->data;
        root->left = delete(root->left,data);
    }
    return root;
}
struct Node*search(struct Node*root, int data){
    while(root!=NULL){
        if(root->data == data){
            printf("Data Found Succesfully");
            return;
        }else if(root->data > data){
            root = root->left;
        }else if(data > root->data){
            root = root->data;
        }
    }
    printf("Data not found:\n");
}
int main(){}