#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Manter como especificado
TipoAluno *alocaAlunos(TipoAluno *alunos, int n){
   alunos = (TipoAluno*) malloc (n * sizeof(TipoAluno));
   return alunos;
}

//Manter como especificado
TipoAluno *desalocaAlunos(TipoAluno *alunos){
  free(alunos);
  alunos = NULL;
  return alunos;
}


void ordena(TipoAluno *alunos, int n){
  char aux[20];
	for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      int k = 0;
      for(int w = 0; w < 20; w++){
        if(alunos[i].nome[k] == alunos[j].nome[k]){
          k++;
        }
      }
      if(alunos[i].nome[k] < alunos[j].nome[k]){
          stpcpy (aux, alunos[i].nome);
          strcpy (alunos[i].nome, alunos[j].nome);
          strcpy (alunos[j].nome, aux);
      }
    }
  }
}
