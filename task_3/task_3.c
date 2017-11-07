#include "defs.h"
#define LENGTH 20
#define S_LENGTH 100

int read_file(char* filename, char*** arr);
//int is_consist(char* s_fn, char* t_fn);

void main(int argc, char* argv[]){
    char** c_arr;
    int count = 0;
    if(argc == 3){
        count = read_file(argv[1], & c_arr);
        for(int i = 0; i < count; i++)
            printf("%s\n", c_arr[i]);
    }
    else 
        exit(1);
}

int read_file(char* filename, char*** arr){
    char** result;	
    int count = 0, j = 0;
    size_t size = sizeof(char*);
    //TODO: add verification for null
    FILE* fp = fopen(filename, "r+");
    
    result = malloc(size);
    while(!feof(fp)){
        if(count > LENGTH * j)
            result = realloc(result, LENGTH * ++j * size);
	char * tmp = malloc(sizeof(char)*S_LENGTH);
        fscanf(fp,"%[^\n]s", tmp);
        getc(fp);
        result[count++] = tmp;
    }
    result = realloc(result, --count * size);
    *arr = result;
    fclose(fp);
    return count;
}


