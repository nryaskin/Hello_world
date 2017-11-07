#include "io.h"

int read_std(double** arr_l, size_t def_l){
    int res_size = 0, j = 1;
    double* arr;
    arr = malloc(sizeof(double) * def_l);
    while(!feof(stdin)){
        if(res_size >= def_l * j){
            arr = realloc(arr, sizeof(double) * def_l * ++j);
        }
        scanf("%lf", arr + res_size++);
    }
    arr = realloc(arr, sizeof(double) * --res_size);
    *arr_l = arr;
    return res_size;
}
