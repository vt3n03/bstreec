// CS2211a 2023, Section 1
// Assignment 5
// Victor Tan
// 251 222 810
// VTAN29
// 2023/12/04
#ifndef MATRIX_H
#define MATRIX_H

#include "bstree.h"

// Type definition for Matrix as a Binary Search Tree (BST)
typedef BStree Matrix;

// Type definitions for Index1, Index2, and Value
typedef Key1 Index1;
typedef Key2 Index2;
typedef float Value;

// Function to initialize and return a new Matrix (BST)
Matrix matrix_construction(void);

// Function to check if an index is present in the Matrix
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2);

// Function to get the value associated with an index in the Matrix
const Value *matrix_get(Matrix m, Index1 index1, Index2 index2);

// Function to set a value for a given index in the Matrix
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value);

// Function to print the Matrix data
void matrix_list(Matrix m);

// Function to free the memory allocated for the Matrix
void matrix_destruction(Matrix m);

#endif // MATRIX_H
