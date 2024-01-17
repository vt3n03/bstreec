// CS2211a 2023, Section 1
// Assignment 5
// Victor Tan
// 251 222 810
// VTAN29
// 2023/12/04
#include "datatype.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Function to initialize and return a new empty Key
Key key_ini() {
    Key new_key = (Key)malloc(sizeof(Key_struct));
    if (new_key == NULL) {
        fprintf(stderr, "Memory allocation error for key.\n");
        exit(EXIT_FAILURE);
    }

    new_key->key1 = NULL;
    new_key->key2 = 0;
    return new_key;
}

// Function to set the values of a Key
void key_set(Key key, Key1 key1, Key2 key2) {
    key->key1 = strdup(key1);
    key->key2 = key2;
}

// Function to compare two Keys
int key_comp(Key key1, Key key2) {
    int cmp = strcmp(key1->key1, key2->key1);
    if (cmp != 0) {
        return cmp;
    }
    return key1->key2 - key2->key2;
}

// Function to print a Key in the format "key1 key2"
void key_print1(Key key) {
    printf("%s %d", key->key1, key->key2);
}

// Function to print a Key in the format "key2 key1"
void key_print2(Key key) {
    printf("%d %s", key->key2, key->key1);
}

// Function to free the memory allocated for a Key
void key_free(Key key) {
    free(key->key1);
    free(key);
}

// Function to initialize and return a new Data
Data data_ini() {
    Data new_data = (Data)malloc(sizeof(float));
    if (new_data == NULL) {
        fprintf(stderr, "Memory allocation error for data.\n");
        exit(EXIT_FAILURE);
    }

    return new_data;
}

// Function to set the value of a Data
void data_set(Data data, float intdata) {
    *data = intdata;
}

// Function to print a Data
void data_print(Data data) {
    printf("%f", *data);
}

// Function to free the memory allocated for a Data
void data_free(Data data) {
    free(data);
}
