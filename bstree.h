// CS2211a 2023, Section 1
// Assignment 5
// Victor Tan
// 251 222 810
// VTAN29
// 2023/12/04
#ifndef BSTREE_H
#define BSTREE_H

#include "datatype.h"

// Structure representing a node in the Binary Search Tree (BST)
typedef struct BStree_node {
    Key key;                // Key of the node
    Data data;              // Data associated with the key
    struct BStree_node *left, *right; // Pointers to the left and right child nodes
} BStree_node;

// Pointer to the root of the Binary Search Tree (BST)
typedef BStree_node** BStree;

// Function to initialize and return an empty Binary Search Tree (BST)
BStree bstree_ini(void);

// Function to insert a new key and data into the Binary Search Tree (BST)
void bstree_insert(BStree bst, Key key, Data data);

// Function to create a new node with the given key and data
BStree_node *new_node(Key key, Data data);

// Function to search for a key in the Binary Search Tree (BST) and return the associated data
Data bstree_search(BStree bst, Key key);

// Function to traverse the Binary Search Tree (BST) in-order and print the data
void bstree_traverse(BStree bst);

// Function to free the memory allocated for the Binary Search Tree (BST) nodes
void bstree_free(BStree bst);

#endif // BSTREE_H
