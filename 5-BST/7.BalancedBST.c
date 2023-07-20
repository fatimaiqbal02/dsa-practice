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
void inorderTraversal(struct Node*root){
    struct Node*p = root;
    if(p!=NULL){
        inorderTraversal(p->left);
        printf("%d\t",p->data);
        inorderTraversal(p->right);
    }
}
struct Node* createBalancedBST(int arr[], int start, int end){

    if(start > end){
        return NULL;
    }
    int mid = (start + end)/2;
    struct Node*ptr = createNode(arr[mid]);
    ptr->left = createBalancedBST(arr,start, mid-1);
    ptr->right = createBalancedBST(arr,mid+1,end);
    return ptr;
   
}
void sortingArray(int arr[],int size){
    int temp;
    for(int i = 0; i<size; i++){
       for(int j = i+1; j<size; j++){
           if(arr[i] > arr[j]){
               temp =  arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
           }
       }
    }
}
int main(){
    int arr[]= {15, 10, 20, 8, 12, 16, 25};
    sortingArray(arr,7);
    struct Node* root = createBalancedBST(arr,0,6);
        
    printf("IN-ORDER traversal:\n");
    inorderTraversal(root);

}