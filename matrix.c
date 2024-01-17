// CS2211a 2023, Section 1
// Assignment 5
// Victor Tan
// 251 222 810
// VTAN29
// 2023/12/04
#include "matrix.h"
#include <stdio.h>
#include <string.h>

// Function to initialize and return a new Matrix (BST)
Matrix matrix_construction(void) {
    return bstree_ini();
}

// Function to check if an index is present in the Matrix
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2) {
    Key key = key_ini();
    key_set(key, index1, index2);
    Data result = bstree_search(m, key);
    key_free(key);

    // Return true if the index is found in the Matrix, otherwise false
    return (result != NULL);
}

// Function to get the value associated with an index in the Matrix
const Value *matrix_get(Matrix m, Index1 index1, Index2 index2) {
    Key key = key_ini();
    key_set(key, index1, index2);
    Data result = bstree_search(m, key);
    key_free(key);

    // Return the value associated with the index in the Matrix
    return result;
}

// Function to set a value for a given index in the Matrix
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value) {
    Key key = key_ini();
    key_set(key, index1, index2);

    const Value *existing_value = matrix_get(m, index1, index2);
    Data data;

    if (existing_value != NULL) {
        // If the key already exists in the matrix, update the value (occurrence count)
        data = (Data)existing_value;
        (*data) += value; // Update occurrence count with the provided value
    } else {
        // If the key doesn't exist, create a new data with the provided value
        data = data_ini();
        data_set(data, value);
        bstree_insert(m, key, data);
    }
}

// Helper function for printing the Matrix data with proper formatting
void matrix_list_helper(BStree_node* root) {
    if (root != NULL) {
        matrix_list_helper(root->left);

        // Calculate the width of each column dynamically based on the length of the data
        int key1_width = strlen(root->key->key1);
        int key2_width = snprintf(NULL, 0, "%d", root->key->key2);
        int data_width = snprintf(NULL, 0, "%.5f", *root->data);

        // Calculate the total width for proper center alignment
        int total_width = key2_width + key1_width + data_width + 4; // 4 is for the spaces between columns
       
        // Print the data with center alignment for all columns
        printf("%*s %-*s %*.5f\n", total_width / 2, root->key->key2, total_width / 2, root->key->key1, data_width, *root->data);

        matrix_list_helper(root->right);
    }
}

// Function to print the Matrix data
void matrix_list(Matrix m) {
    matrix_list_helper(*m);
}

// Function to free the memory allocated for the Matrix
void matrix_destruction(Matrix m) {
    bstree_free(m);
}
