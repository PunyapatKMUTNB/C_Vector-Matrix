#include <stdio.h>
#include "_matrix.c"
#include "_cin_matrix.c"

double **matrix_multiply(double **matfront, double **matback, int mfront, int nfront, int mback, int nback, int print_option){
    if(nfront != mback){
        return 0;
    }
    double **multiplied = matrix(mfront,nback);
    for (int i = 0; i < mfront; i++){
        for (int j = 0; j < nback; j++){
            double final_value = 0;
            for (int k = 0; k < nfront; k++){
                final_value += (matfront[i][k]*matback[k][j]);
            }
            multiplied[i][j] = final_value;
        }
    }
    if(print_option != 0){
        print_matrix(multiplied, mfront, nback);
    }
    return multiplied;
}

int main(int argc, char const *argv[])
{
    double mat1num[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    double mat2num[] = {1,3,2,9,1,6,9,4,1,7,8,1,0,4,1,2,6,1};
    double **mat1 = matrix(4,3);
    cin_fill_matrix(mat1,4,3,mat1num);
    double **mat2 = matrix(3,6);
    cin_fill_matrix(mat2,3,6,mat2num);
    printf("\nMatrix 1\n");
    print_matrix(mat1,4,3);
    printf("\nMatrix 2\n");
    print_matrix(mat2,3,6);
    printf("\nMultiplied Matrix Result\n");
    matrix_multiply(mat1, mat2, 4, 3, 3, 6, 1);
    return 0;
}