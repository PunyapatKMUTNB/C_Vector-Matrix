#include <stdio.h>
#include "_matrix.c"
#include "_cin_matrix.c"
#include "_vector.c"
#include "_cin_vector.c"

double *matrix_multiply_vector(double **mat, double *vec, int mmat, int nmat, int mvec, int print_option){
    if(nmat != mvec){
        return 0;
    }
    
    double *multiplied = vector(mmat);
    for (int i = 0; i < mmat; i++){
        double final_value = 0;
        for (int k = 0; k < nmat; k++){
            final_value += (mat[i][k]*vec[k]);
        }
        multiplied[i] = final_value;
    }
    if(print_option != 0){
        cin_print_vector_vertical(multiplied, mmat);
    }
    return multiplied;
}

int main(int argc, char const *argv[])
{
    double matnum[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    double vecnum[] = {1,3,2};
    double **mat = matrix(4,3);
    cin_fill_matrix(mat,4,3,matnum);
    double *colvec = cin_vector_fill(3, vecnum);
    printf("\nMatrix\n");
    print_matrix(mat,4,3);
    printf("\nVector (Vertical View)\n");
    cin_print_vector_vertical(colvec,3);
    printf("\nMultiplied Matrix and Vector Result\n");
    matrix_multiply_vector(mat, colvec, 4, 3, 3, 1);
    return 0;
}