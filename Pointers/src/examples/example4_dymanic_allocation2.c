#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct runtime_arguments
{
    const char* file_path;
    int array_col_count;
    int array_rows_count;
}typedef runtime_arguments;


runtime_arguments* HandleArguments(int argc,char** argv){
    if(argc != 5){
        printf("ERROR: Wrong number of arguments");
        exit(-1);
    }

    
    runtime_arguments* arguments = malloc(sizeof(runtime_arguments));

    for(int i=1;i<argc;i++){
        if(strcmp(argv[i],"--size")==0){
            i++;
            arguments->array_col_count = atoi(argv[i]);
            arguments->array_rows_count=atoi(argv[i]);
        }
        else if(strcmp(argv[i],"--file")==0){
            i++;
            arguments->file_path = (char*)malloc(sizeof(char)*strlen(argv[i])+1);
            strcpy(arguments->file_path,argv[i]);
        }
        else {
            printf("Error unexpected flag\n");
            exit(1);
        }
    }

    return arguments;

}

void FreeArguments(runtime_arguments* arguments){
    free(arguments->file_path);
    free(arguments);
}


struct Array
{
    int** data;
    int col_count;
    int row_count;
}typedef Array;


Array* InitArray(int col_num,int rows_num){
    Array* arr = malloc(sizeof(Array));
    arr->col_count = col_num;
    arr->row_count = rows_num;
    arr->data = malloc(rows_num * sizeof(int*));

    for(int i=0;i<rows_num;i++){
        arr->data[i] = malloc(col_num * sizeof(int));
    }
    return arr;
} 

void FreeArray(Array* arr){
    for(int i=0;i<arr->row_count;i++)
        free(arr->data[i]);
    free(arr->data);
    free(arr);
}


void FillArrayFromFile(Array* arr,const char* file_path){
       
    char dump;
    FILE* input_file = fopen(file_path, "r");
    for(int i =0;i<arr->row_count;i++){
        for(int j=0;j<arr->col_count;j++)
            fscanf(input_file,"%d",&arr->data[i][j]);
        fprintf(input_file,"%s",&dump);
    }
    fclose(input_file);
}

void PrinArray(Array* arr){
    for(int i =0;i<arr->row_count;i++){
        for(int j=0;j<arr->col_count;j++)
            printf("|%d| ",arr->data[i][j]);
        printf("\n");
    }
}

void IncrementAllElements(Array* arr){
    for(int i =0;i<arr->row_count;i++)
        for(int j=0;j<arr->col_count;j++)
            arr->data[i][j]++;
}



int main(int argc, char **argv)
{
    runtime_arguments* arguments = HandleArguments(argc,argv);
    Array* arr = InitArray(arguments->array_col_count,arguments->array_rows_count);    
    FillArrayFromFile(arr,arguments->file_path);
    PrinArray(arr);
    IncrementAllElements(arr);
    printf("======\n");
    PrinArray(arr);
    FreeArray(arr);
    FreeArguments(arguments);
    return 0;
}