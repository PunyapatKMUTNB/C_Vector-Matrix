#include <stdio.h>
#include "_matrix.c"

// This function is use to transpose the matrix that was passed an an argument then return the new array(pointer) back.
double **transpose_matrix(double **mat, int m, int n){
    // Create a new array for transpose matrix
    double **transposed = matrix(n,m);
    // Start 2 loops. These loops will assig the value of mat[i][j] into transposed[j][i] you can see that the coordinate is swap as these is supposed to be transposed.
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transposed[j][i] = mat[i][j];
        }   
    }
    // Return transposed pointer back to the instruction that called this function.
    return transposed;
}

int main(int argc, char const *argv[])
{
    // Define an array of number from 1 - 9
    double numbers[][9] = {{1,2,3,4,5,6,7,8,9}};
    // Create the matrix with size of 3*3 using the number array that we just created.
    double **prematrix = matrix(3,3);
    // Fill the matrix with number from the array that we just created.
    fill_matrix(prematrix,3,3,numbers[0],3*3);
    print_matrix(prematrix,3,3);
    // Print the transpose matrix 
    print_matrix(transpose_matrix(prematrix,3,3),3,3);
    free_matrix(prematrix,3,3);
    return 0;
}
