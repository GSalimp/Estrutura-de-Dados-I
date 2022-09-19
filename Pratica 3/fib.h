# ifndef fib_h
# define fib_h

typedef struct{
  int numero;
  unsigned long long result;
  unsigned long long chamadas;
} TADFib;

unsigned long long fibonacci(int i, TADFib *f);


# endif
