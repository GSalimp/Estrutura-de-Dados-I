#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct celula{
    int lin;    // linha
    int col;    //coluna
    boolean valid;
};

void desalocaTab(int **tabuleiro){
    for(int i = 0; i < 9; i++){
        free(tabuleiro[i]);
    }
    free(tabuleiro);
    tabuleiro = NULL;
}

void TabuleiroInicializa(char * arquivo, int **tabuleiro) {
    FILE *arq = fopen(arquivo, "r");

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 8; j++)
            fscanf(arq, "%d ", &tabuleiro[i][j]);
        fscanf(arq,"%d\n", &tabuleiro[i][8]);
    }
}

Celula *alocaCelulas(int nro_celulas){
    Celula *celulas = malloc(nro_celulas * sizeof(Celula));
    return celulas;
}

int contaCelulas (int **tabuleiro){
	int nro_vazias = 0;
	for(int i  = 0; i < 9; i++){
		for(int j = 0; j< 9; j++){
			if(tabuleiro[i][j] == 0)
				nro_vazias++;
		}
	}
	return nro_vazias;
}

boolean EhValido(int **tabuleiro,Celula cheia, int **invalidas){
	int i = cheia.lin;
	int j = cheia.col;
	int l = 0;// variavel que irá contar se tem no mínimo uma invalidez
	for(int k  = 0; k < 9; k++){
		if(j != k && tabuleiro[i][k] == tabuleiro[i][j]){//passa por toda a linha na qual a célula está
			invalidas[i][j] = 1;//atribui 1 na posição da celula na matriz 'invalidas' caso tenha um erro na mesma linha
			l++;			
		}			
	}
	for(int k = 0; k<9; k++){
		if(i !=k && tabuleiro[k][j] == tabuleiro[i][j]){//passa por toda a coluna na qual a célula está
			if(invalidas[i][j] != 0)
				invalidas[i][j] = 3;//se ja houver um erro de linha, marca como 3, para efeitos de controle
			else
				invalidas[i][j] = 2;//caso contrário marca como 2
			l++; 
		}
	}
	int x = i;
	int y = j;
	while(x != 0 && x!=3 && x!= 6){
		x--;
	}//este while tem como objetivo atribuir a x a linha na qual começa a região que a célula se encontra
	while(y!= 0 && y!= 3 && y!= 6){
		y--;////este while tem como objetivo atribuir a y a coluna na qual começa a região que a célula se encontra
	}
	for(int k = x; k< x+3; k++){//k começa na linha x, para percorrer apenas a região 3x3 invés do tabuleiro 9x9
		for(int w = y; w< y+3; w++){//w começa na coluna y, para percorrer apenas a região 3x3
			if((k != i && w != j) && tabuleiro[k][w] == tabuleiro[i][j]){
				if(invalidas[i][j] == 1)
					invalidas[i][j] = 4;//se ja houver um erro de linha, marca como 4
				else if(invalidas[i][j] == 2)
					invalidas[i][j] = 5;// se ja houver um erro de coluna marca como 5
				else if(invalidas[i][j] == 3)
					invalidas[i][j] = 6;// se ja houver um erro de linha e coluna marca como 6
				else
					invalidas[i][j] = 7;//se houver apenas o erro de região marca como 7
				l++;
			}
		}
	}
	if(l == 0)// caso l não tenha sofrido incremento, função retorna true
		return true;
	else
		return false;
}

void validador(Celula *cheias, int nro_cheias, int **tabuleiro, int **invalidas){
    for(int i = 0; i<nro_cheias; i++){//roda a função EhValido em todas as células cheias
		cheias[i].valid = EhValido(tabuleiro, cheias[i], invalidas);
    }
}

/*
1=Apenas linha
2=Apenas Coluna
3=Linha e Coluna
4=Linha e Regiao
5=Coluna e Regiao
6= Linha Coluna e Regiao
7=Apenas Regiao*/

Celula* defineVazias(int **tabuleiro, Celula *cheias, int nro_vazias){
    Celula *vazias = malloc(nro_vazias * sizeof(Celula));
    int a= 0;
    int b = 0;
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (tabuleiro[i][j] == 0){
                vazias[a].lin  = i;
				vazias[a].col = j;
				a++;
            }
            else {
                cheias[b].lin = i;
                cheias[b].col = j;
                b++;
            }
        }
    }
    return vazias;
}

void imprimeErros(int **invalidas){
	printf("\nAlguma coisa deu errado... Invalidos:\n");
		for(int i = 0; i < 9; i++){
			int g = i;//atribui inicialmente g = i;
			for(int  j = 0; j < 9; j++){
				if(invalidas[i][j] == 1|| invalidas[i][j] == 3 || invalidas[i][j] == 4 || invalidas[i][j] == 6){
					if(g == i){//na primeira rodagem, o programa vai entrar no if e imprimir a string da linha, mas depois não
						printf("\nLinha %d: ", i+1);
						g++;
					}
					printf("(%d, %d) ", i+1, j+1);
				}
			}
		}
		for(int i = 0; i < 9; i++){
			int g = i;
			for(int  j = 0; j < 9; j++){
				if(invalidas[j][i] == 2 || invalidas[j][i] == 3 || invalidas[j][i] == 5 || invalidas[j][i] == 6){
					if(g == i){
						printf("\nColuna %d: ", i+1);
						g++;
					}
					printf("(%d, %d) ",j+1, i+1);
				}
			}
		}
		int g= -2;
		for(int i = 0; i < 9; i++){
			for(int j = 0; j < 9; j++){
				int a;
				if(i <3 && j < 3) //if's para definir a região
					a = 0;
				else if(i < 3 && j < 6)
					a = 1;
				else if(i < 3 && j < 9)
					a = 2;
				else if(i<6 && j < 3)
					a = 3;
				else if(i < 6 && j < 6)
					a = 4;
				else if(i < 6 && j < 9)
					a = 5;
				else if(i <9 && j < 3)
					a = 6;
				else if(i < 9 && j < 6)
					a = 7;
				else
					a = 8;
				if(invalidas[i][j] == 4 || invalidas[i][j] == 5 || invalidas[i][j] == 6 || invalidas[i][j] == 7){
					if(g != a)
						printf("\nRegiao %d: ", a+1);
					g = a;
					printf("(%d, %d) ", i+1, j+1);		
				}		
			}
		}
}

int* valoresValidos(int **tabuleiro, Celula vazia, int **invalidas){
	int* v_Validos = malloc(9 * sizeof(int));
	int h = 0;
	for(int j = 1; j < 10; j++){
		tabuleiro[vazia.lin][vazia.col] = j;//atribui os valores de 1 a 9 para a célula vazia
		vazia.valid = EhValido (tabuleiro, vazia, invalidas);//valida valor
		if(vazia.valid == true){
			v_Validos[h] = j;//se o valor da vez for válido, adiciona ele no vetor de v_validos e incrementa o h para a próxima adição
			h++;
		}
	}
	for(int i = h; i <9; i++)
		v_Validos[i] = 10;//preenche o resto do vetor com 10 para servir como ponto de parada da impressão
	return v_Validos;
}

void imprimeSugestoes(int nro_vazias, int **tabuleiro, Celula *vazias, int **invalidas){
    printf("\nVoce esta no caminho certo. Sugestoes:\n");
		for(int i = 0; i < nro_vazias; i++){
			int *v_Validos = malloc(9 * sizeof(int));
			v_Validos = valoresValidos(tabuleiro, vazias[i], invalidas);
			printf("(%d, %d):", vazias[i].lin +1, vazias[i].col +1);
			for(int j = 0; j < 9; j++){
				if(v_Validos[j] != 10)//imprime os valores do vetor até chegar no valor 10 e parar
		 			printf(" %d", v_Validos[j]);
			}
			printf("\n");
			free(v_Validos);
			v_Validos = NULL;
		}
}
