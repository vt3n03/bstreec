// CS2211a 2023, Section 1
// Assignment 5
// Victor Tan
// 251 222 810
// VTAN29
// 2023/12/04
#include "matrix.h"
#include <stdio.h>

// Function to read input from a file or stdin and update the matrix
void read_input(Matrix matrix, FILE *input_file) {
    int key2;
    Key1 key1 = (Key1)malloc(256 * sizeof(char)); // Assuming a maximum of 256 characters for key1

    while (fscanf(input_file, "%d %255[^\n]", &key2, key1) != EOF) {
        matrix_set(matrix, key1, key2, 1); // Set the value to 1 for each occurrence
    }

    free(key1);
}

// Function to print the matrix data
void print_matrix(Matrix matrix) {
    printf("Number\t   Street\t      Occurrence\n");

    // Assuming the matrix stores occurrence counts as float values
    bstree_traverse(matrix);
}

int main(int argc, char *argv[]) {
    // Check if an input file is provided
    if (argc == 2) {
        // Open the input file
        FILE *input_file = fopen(argv[1], "r");
        if (input_file == NULL) {
            fprintf(stderr, "Error opening input file: %s\n", argv[1]);
            return EXIT_FAILURE;
        }

        // Create a new Matrix
        Matrix matrix = matrix_construction();
        if (matrix == NULL) {
            fprintf(stderr, "Matrix construction failed.\n");
            fclose(input_file);
            return EXIT_FAILURE;
        }

        // Read from the input file
        read_input(matrix, input_file);

        // Print the data in the Matrix
        printf("\nMatrix Data:\n");
        print_matrix(matrix);

        // Free all allocated memory spaces for the Matrix
        matrix_destruction(matrix);

        // Close the input file
        fclose(input_file);

        return EXIT_SUCCESS;
    } else if (argc > 2) {
        fprintf(stderr, "Usage: %s [input_file]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // If no input file is provided, read from keyboard
    printf("Enter integer string pairs (Ctrl+D to terminate):\n");

    // Create a new Matrix
    Matrix matrix = matrix_construction();
    if (matrix == NULL) {
        fprintf(stderr, "Matrix construction failed.\n");
        return EXIT_FAILURE;
    }

    // Read from the keyboard
    read_input(matrix, stdin);

    // Print the data in the Matrix
    printf("\nMatrix Data:\n");
    print_matrix(matrix);

    // Free all allocated memory spaces for the Matrix
    matrix_destruction(matrix);

    return EXIT_SUCCESS;
}
