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
void inOrderTraversalToArray(int arr[],struct Node*root){
    static int i = 0;
    struct Node*p = root;
    if(p!=NULL){
        inOrderTraversalToArray(arr,p->left);
        arr[i] = p->data;
        i++;
        inOrderTraversalToArray(arr,p->right);
    }
}
int main(){
    int data_to_search;
    createTree(45);
    createTree(15);
    createTree(60);
    createTree(12);
    createTree(97);
    createTree(4);
    createTree(30);
    createTree(150);
    createTree(11);
    createTree(55);
    createTree(85);
    createTree(37);
    
    
    printf("IN-ORDER traversal:\n");
    inorderTraversal(root);
    
    printf("\nPRE-ORDER traversal:\n");
    preOrderTraversal(root);

    printf("\nPRE-ORDER traversal:\n");
    postOrderTraversal(root);
    
    printf("\n\nDeleting 12 and 60 from tree....\n");
    deletion(root,12);
    deletion(root,60);
    printf("\nAfter deleting 12 and 60\nIN-ORDER traversal:\n");
    inorderTraversal(root);

    printf("\nEnter the data to Search in Tree:\n");   
    scanf("%d,",&data_to_search);
    search(root,data_to_search);

   printf("\nInserting 70 and 100 in tree....\n");
   insertion(root,70);
   insertion(root,100);
   printf("\nAfter inserting 70 and 100\nIN-ORDER traversal:\n");
   inorderTraversal(root);

    int arr[12];
    inOrderTraversalToArray(arr,root);
    printf("\nLargest Element = %d\n",arr[11]);
    printf("Smallest Element = %d\n",arr[0]);
   
}