#include "defs.h"
#define LENGTH 20
#define S_LENGTH 100

int read_file(char*** arr);

void main(){
    char** c_arr;
    int count = read_file(& c_arr);
    for(int i = 0; i < count; i++)
        printf("%s\n", c_arr[i]);
}

int read_file(char*** arr){
    char** result;	
    int count = 0, j = 0;
    size_t size = sizeof(char*);
    result = malloc(size);
    while(!feof(stdin)){
        if(count > LENGTH * j)
            result = realloc(result, LENGTH * ++j * size);
	char * tmp = malloc(sizeof(char)*S_LENGTH);
        scanf("%[^\n]s", tmp);
        getc(stdin);
        result[count++] = tmp;
    }
    result = realloc(result, --count * size);
    *arr = result;
    return count;
}
