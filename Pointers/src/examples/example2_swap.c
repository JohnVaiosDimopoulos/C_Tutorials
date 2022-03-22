#include <stdio.h>

void swap_correct(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void swap_wrong(int a,int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void do_print(int* a, int* b){
    printf("var_a is: %d\n",*a);
    printf("var_b is: %d\n",*b);
}


int main(void){
    int var_a = 1;
    int var_b = 2;
    printf("==== Before the swap ====\n");
    do_print(&var_a,&var_b);
    swap_wrong(var_a,var_b);

    printf("=== After the wrong swap ===\n");
    do_print(&var_a,&var_b);

    printf("=== After the correct swap ===\n");
    swap_correct(&var_a,&var_b);
    do_print(&var_a, &var_b);

}