#include <stdio.h>
#include "_matrix.c"
#include "_cin_matrix.c"
#include "_vector.c"
#include "_cin_vector.c"
// Augmentation
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
// Transformation to Reduced Row Echelon
// Using Psudocode from https://en.wikipedia.org/wiki/Row_echelon_form#Pseudocode_for_reduced_row_echelon_form
double **Psudo_ReducedRowEchelon(double **mat, int m, int n){
    int lead = 0;
    for (int r = 0; r < m; r++){
        if(n<=lead) break;
        int i = r;
        while(mat[i][lead] == 0){
            i++;
            if(m == i){
                i = r;
                lead++;
                if(n==lead) break;
            }
        }
        if(i!=r){
            matrix_swap_operation_row(mat, n, i, r);
        }
        double divider = mat[r][lead];
        for (int j = 0; j < n; j++){
            mat[r][j] = mat[r][j]/divider;
        }
        for (int l = 0; l < m; l++){
            if(l!=r){
                double submul = mat[l][lead];
                for (int k = 0; k < n; k++){
                    mat[l][k] -= submul*mat[r][k];
                }
            }
        }
        lead++;
    }
    return mat;
}



double *LinearEqnSolve(double **mat, int size, double *vec, int print_option_augmented, int print_option_solved, int print_option_result){
    double *eqnFinal = vector(size);
    double **augmentedMat = augment(mat, size, size, vec, 0);
    int uniqueness = 1;
    if(print_option_augmented!=0) {
        printf("\nAugmented Matrix Before Being Solved: \n");
        print_matrix(augmentedMat,size,size+1);
    }
    Psudo_ReducedRowEchelon(augmentedMat, size, size+1);
    for (int i = 0; i < size; i++)
    {
        eqnFinal[i] = augmentedMat[i][size];
    }
    if(print_option_solved!=0) {
        printf("\nSolved Matrix: \n");
        print_matrix(augmentedMat,size,size+1);
    }
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size+1; j++)
        {
            if(augmentedMat[i][j] == 0) count++;
            if(count == size+1) uniqueness = 0;
        }
    }
    
    if(print_option_result!=0) {
        printf("\nResult: \n");
        if(uniqueness == 0) printf("The solution isn't unique \n");
        cin_print_vector_vertical(eqnFinal,size);
    }
    return eqnFinal;
}

int main(int argc, char const *argv[])
{
    double **mat = matrix(3,3);
    double **mat2 = matrix(3,3);
    double matnum[] = {8,5,4,3,2,7,9,4,1};
    double vecnum[] = {5,16,8};
    double matnum2[] = {1,3,1,3,-2,-8,4,5,-3};
    double vecnum2[] = {6,7,17};
    cin_fill_matrix(mat,3,3,matnum);
    double *vec = cin_vector_fill(3, vecnum);
    cin_fill_matrix(mat2,3,3,matnum2);
    double *vec2 = cin_vector_fill(3, vecnum2);
    LinearEqnSolve(mat, 3, vec, 1, 1, 1);
    printf("--------------------------------------\n");
    LinearEqnSolve(mat2, 3, vec2, 1, 1, 1);
    return 0;
}
