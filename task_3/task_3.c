#include "defs.h"
#define LENGTH 20
#define S_LENGTH 100

int read_file(char* filename, char*** arr);
int is_consist(char* s_fn, char* t_fn);

void main(int argc, char* argv[]){
    char** c_arr;
    int count = 0;
    if(argc == 3){
        count = read_file(argv[1], & c_arr);
        for(int i = 0; i < count; i++)
            printf("%s\n", c_arr[i]);
        printf("second file can be get from first: %s\n",is_consist(argv[1], argv[2])? "true": "false");
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

int is_in_arr(char** arr, int count, char* word){
    int result = 0;    
    if(word == "")
        result = 1;
    else
        for(int i = 0; i < count; i++)
            if(strcmp(arr[i], word) == 0){
                result = 1;
                break;
            }
    
    return result;
}

//returns 0 in case we can't build from parts of source string new string
//else non negative 1
int is_consist(char* s_fn, char* t_fn){
    char **source_arr;
    char* tmp = malloc(sizeof(char)*S_LENGTH);
    int count = read_file(s_fn, &source_arr), result = 1;
    //TODO: try do something with code duplicating
    FILE* fp = fopen(t_fn, "r+");
    while(!feof(fp)){
        fscanf(fp, "%[^\n]s", tmp);
        getc(fp);
        if(!is_in_arr(source_arr, count, tmp)){
            result = 0;
            break;
        }
    }
    fclose(fp);
    return result;
}
