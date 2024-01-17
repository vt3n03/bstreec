// CS2211a 2023, Section 1
// Assignment 5
// Victor Tan
// 251 222 810
// VTAN29
// 2023/12/04
#ifndef DATATYPE_H
#define DATATYPE_H

#include <stdlib.h>

// Type definition for Data (assumed to be a float*)
typedef float* Data;

// Type definitions for Key1 and Key2
typedef char* Key1;
typedef int Key2;

// Structure representing a Key
typedef struct {
    Key1 key1;
    Key2 key2;
} Key_struct;

// Type definition for Key as a pointer to Key_struct
typedef Key_struct* Key;

// Function to initialize and return a new empty Key
Key key_ini();

// Function to set the values of a Key
void key_set(Key key, Key1 key1, Key2 key2);

// Function to compare two Keys
int key_comp(Key key1, Key key2);

// Function to print a Key in the format "key1 key2"
void key_print1(Key key);

// Function to print a Key in the format "key2 key1"
void key_print2(Key key);

// Function to free the memory allocated for a Key
void key_free(Key key);

// Function to initialize and return a new empty Data
Data data_ini();

// Function to set the value of a Data
void data_set(Data data, float intdata);

// Function to print a Data
void data_print(Data data);

// Function to free the memory allocated for a Data
void data_free(Data data);

#endif // DATATYPE_H
