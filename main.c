//gcc -o cpu main.c cpu.c
#include <stdio.h>
#include "cpu.h"
int main(){
    Cpu mycpu;
    
    printf("moikka :)\n");
    start(&mycpu);
    //reset(&mycpu);
    run(&mycpu);
    return 0;
}