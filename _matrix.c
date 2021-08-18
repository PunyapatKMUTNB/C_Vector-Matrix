#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double **matrix( int m, int n ) {
    double **mat = (double **)malloc( m*sizeof(double*) );
        if ( mat ) { 
            for ( int i=0; i < m; i++ ) {
                    mat[i] = (double *)malloc( n*sizeof(double) );
                }
        }
    return mat;
}


void free_matrix( double **mat, int m, int n ) {
    if (mat) {
        for ( int i=0; i < n; i++ ) {
            if (mat[i]) free(mat[i]);
        }
    free(mat);
    }
}


double **copy_matrix( double **dst, double **src, int m, int n ) {
    for ( int r=0; r < m; r++ ) {
        for ( int c=0; c < n; c++ ) {
            dst[r][c] = src[r][c];
        }
    }
        return dst;
}


double **fill_matrix( double **mat, int m, int n, double *vec, int len ) {
    int r, c;
    for ( int i=0; i < len; i++ ) {
        r = i/n;
        c = i%m;
        mat[r][c] = vec[i];
    }
    return mat;
}


double **zero_matrix( double **mat, int m, int n ) {
    for ( int r=0; r < m; r++ ) {
        for ( int c=0; c < n; c++ ) {
            mat[r][c] = 0;
        }
    }
    return mat;
}


void print_matrix( double **mat, int m, int n ) {
    printf("[\n");
    for ( int r=0; r < m; r++ ) {
        printf(" [ ");
        for ( int c=0; c < n; c++ ) {
            printf( "%+.3lf ", mat[r][c] );
        }   
        printf("]\n");
    }
    printf("]\n");
}
