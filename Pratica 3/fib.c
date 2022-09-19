#include "fib.h"
#include<stdio.h>
#include<stdlib.h>

unsigned long long fibonacci(int i, TADFib *f){
    if(i == 0)
        return 0;
    else if(i == 1)
        return 1;
    else{
        f->chamadas += 2;
        return fibonacci(i - 1, f) + fibonacci(i - 2, f);
    }
}