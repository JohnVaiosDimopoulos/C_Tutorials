#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct runtime_arguments
{
    char* name;
} typedef runtime_arguments;

runtime_arguments* HandleArguments_1(int argc, char** argv){

    if(argc != 2){
        printf("Error: Expecting only one argument\n");
        exit (-1);
    }

    runtime_arguments*  arguments =  malloc(sizeof(runtime_arguments));
    arguments->name = (char*)malloc(strlen(argv[1])*sizeof(char)+1);
    strcpy(arguments->name,argv[1]);

    return arguments;

}

void PrintArguments_1(runtime_arguments* args){
    printf("%s\n",args->name);
}

runtime_arguments HandleArguments_2(int argc,char** argv){

    if(argc != 2){
        printf("Error: Expecting only one argument\n");
        exit (-1);
    }

    runtime_arguments  arguments;
    arguments.name = malloc(strlen(argv[1])*sizeof(char));
    strcpy(arguments.name,argv[1]);

    printf("Inside the funct: %p\n",&arguments);
    return arguments;

}

void PrintArguments_2(runtime_arguments args){
    printf("%s\n",args.name);
}

int main(int argc, char **argv)
{
    runtime_arguments* args = HandleArguments_1(argc,argv);
    runtime_arguments args_2 = HandleArguments_2(argc,argv);
    printf("Outsie the funct: %p\n",&args_2);


    PrintArguments_1(args);
    PrintArguments_2(*args);
    PrintArguments_2(args_2);
    PrintArguments_1(&args_2);

    free(args_2.name);
    free(args->name);
    free(args);

    return 0;
}
