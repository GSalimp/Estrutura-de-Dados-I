#ifndef sudoku_h
#define sudoku_h

typedef struct celula Celula;

typedef int boolean;
enum { false, true };

void desalocaTab(int **tabuleiro);

Celula *alocaCelulas(int nro_celulas);

void TabuleiroInicializa(char * arquivo, int **tabuleiro);

int contaCelulas (int **tabuleiro);

boolean EhValido(int **tabuleiro,Celula cheia, int **invalidas);

void validador(Celula *cheias, int nro_cheias, int **tabuleiro, int **invalidas);

Celula* defineVazias(int **tabuleiro, Celula* cheias, int nro_vazias);

void imprimeErros(int **invalidas);

void imprimeSugestoes(int nro_vazias, int **tabuleiro, Celula *vazias, int **invalidas);

int* valoresValidos(int **tabuleiro, Celula vazia,int **invalidas);

#endif
