#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "_matrix.c"

// This function will assign 1 to the matrix coordinate that has the same number.
double **fill_ident_matrix(double **mat, int m){
    for (int i = 0; i < m; i++)
    {
        mat[i][i] = 1;
    }
    return mat;
}

// Create an s*s matrix then assign 1 into all coordinate that has the same number.
double **ident_matrix(int s){
    double **mat = (double **)malloc( s*sizeof(double*) );
        if ( mat ) { 
            for ( int i=0; i < s; i++ ) {
                    mat[i] = (double *)malloc( s*sizeof(double) );
                }
        }
    fill_ident_matrix(mat,s);
    return mat;
}

// Swap the value of destination and source row.
double **matrix_swap_operation_row(double **mat, int s, int src, int des){
    // Create an array for the destination row.
    double destinationRow[s];
    // Keep all of the destination row value into the array.
    for (int i = 0; i < s; i++)
    {
        destinationRow[i] = mat[des][i];
    }
    // Start copying value from source row to the destination row
    for (int i = 0; i < s; i++)
    {
        mat[des][i] = mat[src][i];
    }
    // Copy value from destination row to the source row from the array that we just created
    for (int i = 0; i < s; i++)
    {
        mat[src][i] = destinationRow[i];
    }
    return mat;
}

// Swap the value of destination and source column.
double **matrix_swap_operation_column(double **mat, int s, int src, int des){
    // Create an array for the destination column.
    double destinationColumm[s];
    // Keep all of the destination column value into the array.
    for (int i = 0; i < s; i++)
    {
        destinationColumm[i] = mat[i][des];
    }
    // Start copying value from source column to the destination column
    for (int i = 0; i < s; i++)
    {
        mat[i][des] = mat[i][src];
    }
    // Copy value from destination column to the source column from the array that we just created
    for (int i = 0; i < s; i++)
    {
        mat[i][src] = destinationColumm[i];
    }
    return mat;
}

// Create a permutation matrix using row swapping.
double **permute_matrix_row(int s){
    // Get the identity matrix using ident_matrix function
    double **mat = ident_matrix(s);
    srand(time(NULL));
    for (int i = 0; i < s; i++)
    {
        // Random the destination index number to swap the row.
        int random_index = rand() % s;
        // Use funtion to swap the row between source and destination 
        matrix_swap_operation_row(mat, s, i, random_index);
    }
    return mat;
}

// Create a permutation matrix using column swapping.
double **permute_matrix_column(int s){
    // Get the identity matrix using ident_matrix function
    double **mat = ident_matrix(s);
    srand(time(NULL));
    for (int i = 0; i < s; i++)
    {
        // Random the destination index number to swap the column.
        int random_index = rand() % s;
        // Use funtion to swap the column between source and destination 
        matrix_swap_operation_column(mat, s, i, random_index);
    }
    return mat;
}

int main(int argc, char const *argv[])
{
    int matrix_size = 3;
    print_matrix(permute_matrix_row(matrix_size),matrix_size,matrix_size);
    print_matrix(permute_matrix_column(matrix_size),matrix_size,matrix_size);
    return 0;
}
