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
void createTree(struct Node** root, int data){
    if(*root == NULL){
        *root = createNode(data);
    }else{
        struct Node*prev = NULL;
        struct Node*ptr = createNode(data);
        struct Node*p = *root;
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
void InOrderArray(int arr[],struct Node*root){
    static int i = 0;
    struct Node*p = root;
    if(p!=NULL){
        InOrderArray(arr,p->left);
        arr[i] = p->data;
        i++;
        InOrderArray(arr,p->right);
    }
}
void findPairWithSum(int arr[],int size, int sum){
    int flag = 0;
    for(int i = 0;i<size;i++){
        for(int j = i+1; j<size;j++){
            if(arr[i] + arr[j] == sum){
                printf("Pair is Present:\n");
                printf("(%d, %d)",arr[i],arr[j]);
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            printf("Pair is Not Present:\n");
        }
    }
}
int main(){
    struct Node*root = NULL;
    int data;
    for(int i = 0; i<11; i++){
        printf("Enter the Data:\n");
        scanf("%d",&data);
        createTree(&root, data);
    }
    
    printf("IN-ORDER traversal:\n");
    inorderTraversal(root);
    printf("\n");

    int arr[7];
    InOrderArray(arr,root);
    findPairWithSum(arr,11,14);
    
}