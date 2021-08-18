#include <stdio.h>
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
    // create s*s matrix that has 0 as all of the value.
    double **mat = (double **)malloc( s*sizeof(double*) );
        if ( mat ) { 
            for ( int i=0; i < s; i++ ) {
                    mat[i] = (double *)malloc( s*sizeof(double) );
                }
        }
    // Assign 1 to the matrix coordinate that has the same number.
    fill_ident_matrix(mat,s);
    return mat;
}

int main(int argc, char const *argv[])
{
    // Define n = 3 as the matrix size.
    int n = 3;
    double **matrix1 = ident_matrix(n);
    // Print the processed matrix.
    print_matrix(matrix1, n, n);
    free_matrix(matrix1, n, n);
    return 0;
}
