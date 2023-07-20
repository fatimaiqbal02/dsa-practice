#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int data;
    struct Tree *leftLink, *rightLink;
} Tree;

void insert(Tree **root, int data);
void displayInOrder(Tree *root);
void displayPostOrder(Tree *root);
void displayPreOrder(Tree *root);
bool searchNode(Tree *root, int searchItem,Tree **lastNode);
void deleteNode(Tree *root, int delItem);

void main() {
    Tree *rootNode = NULL, *lastSearchNode = NULL;

    insert(&rootNode, 45);
    insert(&rootNode, 15);
    insert(&rootNode, 60);
    insert(&rootNode, 12);
    insert(&rootNode, 97);
    insert(&rootNode, 4);
    insert(&rootNode, 30);
    insert(&rootNode, 150);
    insert(&rootNode, 11);
    insert(&rootNode, 55);
    insert(&rootNode, 85);
    insert(&rootNode, 37);


    deleteNode(rootNode, 150);
    displayInOrder(rootNode);

}

void insert(Tree **root, int data) {
    Tree *newNode = *root;
    if (*root == NULL) {
        newNode = (Tree *) malloc (sizeof (Tree));
        newNode->data = data;
        newNode->leftLink = NULL;
        newNode->rightLink = NULL;
        *root = newNode;
    }
    if (newNode->data > data) {
        insert(&newNode->leftLink, data);
    } else if (newNode->data < data) {
        insert(&newNode->rightLink, data);
    }
}

void displayInOrder(Tree *root) {
    if (root!= NULL) {
        displayInOrder(root->leftLink);
        printf ("%d\t", root->data);
        displayInOrder(root->rightLink);
    }
}

void displayPostOrder(Tree *root) {
    if (root!= NULL) {
        displayPostOrder(root->leftLink);
        displayPostOrder(root->rightLink);
        printf ("%d\t", root->data);
    }
}

void displayPreOrder(Tree *root) {
    if (root != NULL) {
        displayPreOrder(root->leftLink);
        printf ("%d\t", root->data);
        displayPreOrder(root->rightLink);
    }
}

bool searchNode(Tree *root, int searchItem, Tree **lastNode) {
    while (root != NULL) {
        if (searchItem > root->data) {
            *lastNode = root;
            root = root->rightLink;
        } else if (searchItem < root->data) {
            *lastNode = root;
            root = root->leftLink;
        } else if (searchItem == root->data) {
            return true;
        }
    }
    return false;
}

void deleteNode(Tree *root, int delItem) {
    Tree ***targetNode;
    if (searchNode(root, delItem, (*(*targetNode))) == false) {
        printf("Not Found");
        return;
    }

    Tree **currentNode = **targetNode;
    Tree **previousNode = *currentNode;
    int flag = 0;

    if ((*currentNode)->data > delItem) {
        flag = 1;
        (*currentNode) = (*currentNode)->leftLink;
    } else {
        (*currentNode) = (*currentNode)->rightLink;
    }

    if ((*currentNode)->leftLink == NULL && (*currentNode)->rightLink == NULL) {
        free(*currentNode);
        if (flag == 1) {
            (*previousNode)->leftLink = NULL;
        } else {
            (*previousNode)->rightLink = NULL;
        }

    }

}