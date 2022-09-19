#include "aluno.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno {
  char nome[20];
  char curso[20];
  double nota;
};

struct turma {
  TAluno **pAluno;
  int qtdAlunos;
};

void lerInfos(int *qtd, char *option) {
  scanf("%c", option);
  scanf("%d", qtd);
}

void alocaAluno(TAluno **pAluno) {
  *pAluno = malloc(sizeof(TAluno));
}

void alocaTurma(TTurma **pTurma, int qtd) {
  *pTurma = malloc(sizeof(TTurma));
  (*pTurma)->qtdAlunos = qtd;
  (*pTurma)->pAluno = malloc((*pTurma)->qtdAlunos*sizeof(TAluno));
  for(int i = 0; i < (*pTurma)->qtdAlunos; i++){
    alocaAluno(&(*pTurma)->pAluno[i]);
  }
}

void desalocaAluno(TAluno **pAluno) {
  free(*pAluno);
}

void desalocaTurma(TTurma **pTurma) {
  for(int i = 0; i < (*pTurma)->qtdAlunos; i++){
    desalocaAluno(&(*pTurma)->pAluno[i]);
  }
  free(*pTurma);
}

void lerTurma(TTurma *pTurma) {
  for(int i = 0; i < pTurma->qtdAlunos; i++){
    scanf("%s", pTurma->pAluno[i]->nome); 
    scanf("%s", pTurma->pAluno[i]->curso);
    scanf("%lf", &pTurma->pAluno[i]->nota);
  }
}

float calcularMetrica(TTurma *pTurma, char* curso, char option) {
  float soma = 0;
  int contaAlunos = 0;//contador para contar alunos do curso escolhido
  for(int i = 0; i < pTurma ->qtdAlunos; i++){
    if(strcmp(pTurma->pAluno[i]->curso, curso) ==0){
      soma += pTurma->pAluno[i]->nota;
      contaAlunos++;
    }
  }
  
  if(option == 'M'){
    soma = soma/contaAlunos;
  }

  return soma;
}

void printMetrica(char* curso, float metrica, char option) {
  printf("A %s no curso de %s eh %.1f\n", option == 'S' ? "soma" : "media", curso, metrica);
}
