#include <stdio.h>
#include "_matrix.c"
#include "_cin_matrix.c"
#include "_vector.c"
#include "_cin_vector.c"

double **Cin_ReducedRowEchelon(double **mat, int row, int col){
    for (int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            if(c>r) continue;
            if(c == r){
                if(mat[r][c] == 0 || mat[r][c] == 1) continue;
                double tempdiaganol = mat[r][r];
                for (int i = 0; i < col; i++) {
                    mat[r][i] = mat[r][i]/tempdiaganol;
                }
            }
            if(c!=r){
                double multiplier = mat[r][c];
                if(mat[r][c] != 0){
                    for(int i = 0; i < col; i++){
                        mat[r][i] -= multiplier*mat[c][i];
                    }
                }
            }
        }
    }
    for(int r = 0; r < row; r++){
        for (int c = 0; c < col; c++){
            if(c == r){
                if(mat[r][c] == 0 || mat[r][c] == 1) continue;
                double tempdiaganol = mat[r][r];
                for (int i = 0; i < col; i++) {
                    mat[r][i] = mat[r][i]/tempdiaganol;
                }
            }
            if(c!=r){
                if(c>=row) continue;
                double multiplier = mat[r][c];
                if(mat[r][c] != 0){
                    for(int i = 0; i < col; i++){
                        mat[r][i] -= multiplier*mat[c][i];
                    }
                }
            }
        }
    }
    return mat;
}

int main(int argc, char const *argv[])
{
    double **mat = matrix(4,3);
    double matnum[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    cin_fill_matrix(mat,3,4,matnum);
    printf("\nMatrix before getting transformed into Reduced Row Echelon form:\n");
    print_matrix(mat,3,4);
    Cin_ReducedRowEchelon(mat,3,4);
    printf("\n-----------------------------------------------------------\n");
    printf("\nMatrix in Reduced Row Echelon form:\n");
    print_matrix(mat,3,4);
    return 0;
}
