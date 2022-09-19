#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(int n) {
  TipoAluno *vetor = calloc(n, sizeof(TipoAluno));
  return vetor;
}

//Manter como especificado
void desalocaAlunos(TipoAluno **alunos) {
  free((*alunos));
}

void Heapsort(TipoAluno *alunos, int n) {
  heapConstroi(alunos, n);
  TipoAluno aux;
  int m = n;
  while(m > 1){
    aux = alunos[m-1];
    alunos[m-1] = alunos[0];
    alunos[0] = aux;
    m--;
    heapRefaz(alunos, 0, m-1);
  }
}

void heapRefaz(TipoAluno *alunos, int esq, int dir){
  int i = esq;
  int j = i * 2 + 1;
  TipoAluno aux = alunos[i];
  while (j <= dir){
    if(j < dir && compare(alunos[j].nome, alunos[j+1].nome) < 0){
      j = j+1;
    }
    if(compare(aux.nome, alunos[j].nome) > 0 || compare(aux.nome, alunos[j].nome) == 0){
      break;
    }
    alunos[i] = alunos[j];
    i = j;
    j = (i*2) + 1;
  }
  alunos[i] = aux;
}

int compare(char *nome1, char *nome2){
  return (strcmp(nome1, nome2));
}

void heapConstroi(TipoAluno *alunos, int n){
  int esq = (n/2) - 1;
  while(esq >= 0){
    heapRefaz(alunos, esq, n-1);
    esq--;
  }
}
