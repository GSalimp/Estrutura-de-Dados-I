// Felipe Camargos Cotta 21.1.4007
// Guilherme Salim Monteiro 21.1.4109
//diretivas de compilação: gcc -c main.c -Wall gcc -c sudoku.c -Wall gcc main.o sudoku.o -o exe
#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char** argv){
     if ( argc < 2) {
         printf ("Uso : %s <arquivo_tabuleiro>\n", argv [0]) ;
         return 0;
	}
    int **tabuleiro;
	tabuleiro = malloc(9 * sizeof(int*)); 
	for(int i = 0; i<9;i++)
		tabuleiro[i] = malloc(9*sizeof(int));
    int **invalidas;
	invalidas = malloc(9*sizeof(int*));
	for(int i = 0; i < 9; i++)
		invalidas[i] = malloc(9*sizeof(int));
    TabuleiroInicializa(argv[1], tabuleiro);

    int nro_vazias = contaCelulas(tabuleiro);
    int nro_cheias = (81 - nro_vazias);
    
    Celula *vazias = alocaCelulas(nro_vazias);
    Celula *cheias = alocaCelulas(nro_cheias);
    vazias = defineVazias(tabuleiro, cheias, nro_vazias);
    
    int nro_invalidas = 0;
	validador(cheias, nro_cheias, tabuleiro, invalidas);
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(invalidas[i][j] != 0)
				nro_invalidas++;// checa número de inválidas, para saber se o tabuleiro é ou não válido
		}
	}
	printf("\n\n");
	for(int i = 0; i < 10; i++){
		if(i == 0)
			printf("X ");
		else
			printf(" %d", i);
	}
	printf("\n");
	printf("---------------------\n");
	for(int i = 0; i<9; i++){
		printf("%d| ", i+1);
		for(int j = 0; j<9;j++){
			printf("%d ", tabuleiro[i][j]);
		}
		printf("\n");
	}
	if(nro_vazias == 0 && nro_invalidas == 0){//se o tabuleiro estiver completo e válido encerra o prog
		printf("\n\nJogo completo. Voce ganhou!\n");
		return 0;
	}
	
	if(nro_invalidas != 0){//se não estiver válido (completo ou não) imprime os problemas
		imprimeErros(invalidas);
	}
	else{
		imprimeSugestoes(nro_vazias, tabuleiro, vazias, invalidas);//se estiver válido mas não completo, imprime sugestões
	}
	desalocaTab(tabuleiro);
	desalocaTab(invalidas);
	free(vazias);
	vazias = NULL;
	free(cheias);
	cheias = NULL;

    return 0;
}
