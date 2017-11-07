#include "defs.h"
#include "io.h"
#define LENGTH 20

int count(double *arr, int count);

void main(){
    int i = 0, j = 1, result = 0;
    double* arr = NULL;// = malloc(sizeof(double) * LENGTH);
    int size = read_std(&arr, LENGTH);
    printf("size = %d\n", size);
    for(int l = 0; l < size; l++)
        printf("%lf\n", arr[l]);
    result = count(arr, size);
    printf("result = %d\n", result);
    free(arr);
}

int count_up(double *arr, int count){
    int inv_res = 1, tmp_res = 0, tmp_val = 0;
    for(int i = 1; i < count; i++){
        if(arr[0] <= arr[i]){
            tmp_val = count_up(arr + i, count - i);
            if(tmp_val > tmp_res)
                tmp_res = tmp_val; 
        }
    } 
    inv_res += tmp_res;
    return inv_res;
}

int count_down(double *arr, int count){

    int inv_res = 1, tmp_res = 0, tmp_val = 0;
    for(int i = 1; i < count; i++){
        if(arr[0] >= arr[i]){
            tmp_val = count_down(arr + i, count - i);
            if(tmp_val > tmp_res)
                tmp_res = tmp_val; 
        }
    } 
    inv_res += tmp_res;
    return inv_res;
}

int count(double *arr, int count){
    int c_d = count - count_down(arr, count);
    int c_u = count - count_up(arr, count);
    return c_d < c_u ? c_d: c_u;
}
