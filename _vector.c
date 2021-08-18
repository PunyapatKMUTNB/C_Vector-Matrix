#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double *vector( int n ) {
    double *v = (double *)malloc( n*sizeof(double) );
    if (v == NULL) { 
        printf("cannot allocate memory\n");
    }
    return v;
}


void free_vector( double *v ) {
    if (v) free(v);
}


double *copy_vector( double *dst, const double *src, int n ){
    for (int i=0; i < n; i++ ) {
        dst[i] = src[i];
    }
    return dst;
}


double *zero_vector( double *v, int n ) {
    memset( v, 0, n );
    return v;
}


double dot_prod_vector( double *a, double *b, int n ) {
    double prod_sum = 0.0;
    for ( int i=0; i < n; i++ ) {
        prod_sum += a[i]*b[i];
    }
    return prod_sum;
}


void print_vector( double *v, int n ) {
    printf("[ ");
    for (int i=0; i < n; i++ ) {
        printf( "%+.3lf ", v[i] );  
    }
    printf("]\n");
}


double *addsub_vector( 
    double *result, double *a, double *b, int n, int addsub ) 
{
    for ( int i=0; i < n; i++) {
        result[i] = a[i] + ((addsub==0) ? b[i] : -b[i]);
    }
    return result;
}