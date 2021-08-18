#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double *cin_vector_fill( int n , double* fill) {
    double *v = (double *)malloc( n*sizeof(double) );
    if (v == NULL) { 
        printf("cannot allocate memory\n");
    }
    for (int i=0; i < n; i++ ) {
        v[i] = fill[i];
    }
    return v;
}

double *cin_fill_vector( double *vecmain, double *vecin, int len ){
    for (int i=0; i < len; i++ ) {
        vecmain[i] = vecin[i];
    }
    return vecmain;
}

void cin_print_vector_vertical( double *v, int n ) {
    printf("[\n");
    for (int i=0; i < n; i++ ) {
        printf( " [ %+.3lf ] \n", v[i] );  
    }
    printf("]\n");
}