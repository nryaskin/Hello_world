#include "defs.h"
#include "io.h"
#define LENGTH 20

void main(){
    int i = 0, j = 1;
    double* arr = NULL;// = malloc(sizeof(double) * LENGTH);
    int size = read_std(&arr, LENGTH);
    printf("size = %d\n", size);
    for(int l = 0; l < size; l++)
        printf("%lf\n", arr[l]);
    free(arr);
}

int count(double *arr, int count){
    arr[0];
}
