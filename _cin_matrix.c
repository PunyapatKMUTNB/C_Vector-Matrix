#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double **cin_fill_matrix( double **mat, int m, int n, double *vec) {
    int max_row = m;
    int max_col = n;
    int cur_row = 0;
    int cur_col = 0;
    int len = m*n;
    for ( int i=0; i < len; i++ ) {
        if(cur_col == max_col){
            if(cur_row == max_row){
                mat[cur_row][cur_col] = vec[i];
                break;
            }
            cur_row++;
            cur_col = 0;
        }
        mat[cur_row][cur_col] = vec[i];
        cur_col++;
    }
    return mat;
}

double **matrix_swap_operation_row(double **mat, int s, int src, int des){
    double destinationRow[s];
    for (int i = 0; i < s; i++)
    {
        destinationRow[i] = mat[des][i];
    }
    for (int i = 0; i < s; i++)
    {
        mat[des][i] = mat[src][i];
    }
    for (int i = 0; i < s; i++)
    {
        mat[src][i] = destinationRow[i];
    }
    return mat;
}
