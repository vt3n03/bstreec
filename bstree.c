// CS2211a 2023, Section 1
// Assignment 5
// Victor Tan
// 251 222 810
// VTAN29
// 2023/12/04
#include "bstree.h"
#include <stdlib.h>
#include <stdio.h>

// Create a new BST node with the given key and data
BStree_node* new_node(Key key, Data data) {
    BStree_node* node = (BStree_node*)malloc(sizeof(BStree_node));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation error for BST node.\n");
        exit(EXIT_FAILURE);
    }

    node->key = key;
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Initialize a new BST
BStree bstree_ini(void) {
    BStree bst = (BStree)malloc(sizeof(BStree_node*));
    if (bst == NULL) {
        fprintf(stderr, "Memory allocation error for BST.\n");
        exit(EXIT_FAILURE);
    }

    *bst = NULL;
    return bst;
}

// Helper function for inserting a new node into the BST
void bstree_insert_helper(BStree_node** root, Key key, Data data) {
    if (*root == NULL) {
        *root = new_node(key, data);
    } else {
        int cmp = key_comp(key, (*root)->key);
        if (cmp < 0) {
            bstree_insert_helper(&(*root)->left, key, data);
        } else if (cmp > 0) {
            bstree_insert_helper(&(*root)->right, key, data);
        }
        // If cmp == 0, do nothing (key already exists)
    }
}

// Insert a new key and data into the BST
void bstree_insert(BStree bst, Key key, Data data) {
    BStree_node *newNode = new_node(key, data);

    if (*bst == NULL) {
        *bst = newNode;
    } else {
        int cmp = key_comp(key, (*bst)->key);
        if (cmp < 0) {
            bstree_insert(&((*bst)->left), key, data);
        } else if (cmp > 0) {
            bstree_insert(&((*bst)->right), key, data);
        } else {
            // Key already exists, update the data
            (*bst)->data = data;
            key_free(key); // Free the key since it's not needed
            key_free((*bst)->key); // Free the old key
        }
    }
}

// Helper function for searching a key in the BST
Data bstree_search_helper(BStree_node* root, Key key) {
    if (root == NULL) {
        return NULL;
    }

    int cmp = key_comp(key, root->key);
    if (cmp < 0) {
        return bstree_search_helper(root->left, key);
    } else if (cmp > 0) {
        return bstree_search_helper(root->right, key);
    } else {
        return root->data;
    }
}

// Search for a key in the BST
Data bstree_search(BStree bst, Key key) {
    if (*bst == NULL) {
        return NULL;
    }

    int cmp = key_comp(key, (*bst)->key);
    if (cmp < 0) {
        return bstree_search(&((*bst)->left), key);
    } else if (cmp > 0) {
        return bstree_search(&((*bst)->right), key);
    } else {
        return (*bst)->data;
    }
}

// Helper function for traversing the BST in-order and printing the data
void bstree_traverse_helper(BStree_node* root) {
    if (root != NULL) {
        bstree_traverse_helper(root->left);
        printf("%4d     %-20s %5d\n", root->key->key2, root->key->key1, (int)(*root->data));
        bstree_traverse_helper(root->right);
    }
}

// Traverse the BST in-order and print the data
void bstree_traverse(BStree bst) {
    bstree_traverse_helper(*bst);
}

// Helper function for freeing the memory allocated for the BST nodes
void bstree_free_helper(BStree_node* root) {
    if (root != NULL) {
        bstree_free_helper(root->left);
        bstree_free_helper(root->right);
        key_free(root->key);
        data_free(root->data);
        free(root);
    }
}

// Free the memory allocated for the BST
void bstree_free(BStree bst) {
    bstree_free_helper(*bst);
    free(bst);
}
