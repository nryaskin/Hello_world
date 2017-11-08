#include "defs.h"

//read from stdin arr of ints in arr[N*N]
//and returns N
int read_std(int** arr){
    int count = 0, n = 0, ns = 0;
    int* res = NULL;
    
    while(!feof(stdin)){
        if(count == ns){
            ns = ++n * n;
            res = realloc(res, sizeof(int) * ns); 
        } 
	scanf("%d", res + count++);
    }
    res = realloc(res, sizeof(int) * (--n * n));
    *arr = res;
    return n;
}

void main(){
    int* arr = NULL;
    
    int n = read_std(& arr);

    for(int i = 0; i < n; i++){
	  for(int j = 0; j < n; j++) 
		 printf("%d\t",arr[i * n + j]);
        printf("\n");
    } 
}
