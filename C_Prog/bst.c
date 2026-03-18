#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int value){
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int value){
    if(root == NULL){
        return create(value);
    } else if(value < root->data){
        root->left = insert(root->left, value);
    } else if(value > root->data){
        root->right = insert(root->right, value);
    }
    return root;
}

struct node *search(struct node *root, int key){
    if(root == NULL || root->data == key){
        return root;
    } else if(key < root->data){
        return search(root->left, key);
    } else{
        return search(root->right, key);
    }
}

struct node *findMin(struct node *root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct node *delete(struct node *root, int key){
    if(root == NULL){
        return root;
    } else if(key < root->data){
        root->left = delete(root->left, key);
    } else if(key > root->data){
        root->right = delete(root->right, key);
    } else {
        // Node found
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        } else if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        } else {
            struct node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);

    printf("Inorder (after insertion): ");
    inorder(root);
    printf("\n");

    int key = 40;
    struct node *result = search(root, key);
    if(result != NULL){
        printf("Found: %d\n", key);
    } else {
        printf("Not found: %d\n", key);
    }

    root = delete(root, 30);
    printf("Inorder (after deletion of 30): ");
    inorder(root);
    printf("\n");

    return 0;
}



   