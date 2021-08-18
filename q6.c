#include <stdio.h>
#include "_matrix.c"
#include "_cin_matrix.c"
#include "_vector.c"
#include "_cin_vector.c"

double **augment(double **mat, int m, int n, double *vec, int print_option){
    double** augmented_matrix = matrix(m, n+1);
    copy_matrix(augmented_matrix, mat, m, n);
    for (int i = 0; i < m; i++)
    {
        augmented_matrix[i][n] = vec[i];
    }
    if(print_option != 0){
        print_matrix(augmented_matrix,m,n+1);
    }
    return augmented_matrix;
}

int main(int argc, char const *argv[])
{
    double matnum[] = {1,2,3,4,5,6,7,8,9};
    double vecnum[] = {9,6,4};
    double **mat = matrix(3,3);
    double *vec = cin_vector_fill(3, vecnum);
    cin_fill_matrix(mat,3,3,matnum);
    printf("\nMatrix\n");
    print_matrix(mat,3,3);
    printf("\nVector\n");
    cin_print_vector_vertical(vec,3);
    printf("\nAugmented Matrix\n");
    augment(mat,3,3,vec,1);
    return 0;
}
