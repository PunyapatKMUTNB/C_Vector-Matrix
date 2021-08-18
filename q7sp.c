#include <stdio.h>
#include "_matrix.c"
#include "_cin_matrix.c"
#include "_vector.c"
#include "_cin_vector.c"

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

int main(int argc, char const *argv[])
{
    double **mat = matrix(4,3);
    double matnum[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    cin_fill_matrix(mat,3,4,matnum);
    printf("\nMatrix before getting transformed into Reduced Row Echelon form:\n");
    print_matrix(mat,3,4);
    Psudo_ReducedRowEchelon(mat,3,4);
    printf("\n-----------------------------------------------------------\n");
    printf("\nMatrix in Reduced Row Echelon form:\n");
    print_matrix(mat,3,4);
    return 0;
}
