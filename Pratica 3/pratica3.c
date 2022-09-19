#include "fib.h"
#include<stdio.h>

int main()
{
    int n;
    TADFib f;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &f.numero);
        f.chamadas = 0;
        f.result = fibonacci(f.numero, &f);
        printf("fib(%d) = %llu chamadas = %llu\n", f.numero, f.chamadas, f.result);
    }
    return 0;
}
