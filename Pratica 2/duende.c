#include "duende.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct duende{
  char nome [20];
  int idade;
  int escalado;
};

struct time{
  char lider[20];
  char entregador[20];
  char piloto[20];
  int idadeLider;
  int idadePiloto;
  int idadeEntregador;
};

void lerQuantidade(int *qtd){
  scanf("%d", qtd);
}


TADduende *alocaDuendes(int qtd){
  TADduende *D;
  D = malloc(qtd * sizeof(TADduende));
  return D;
}

TADtime *alocaTimes(int qtd){
  TADtime *T;
  T = malloc(qtd * sizeof(TADtime));
  return T;
}

void desalocaDuendes(TADduende **D){
  free(*D);
}

void desalocaTimes(TADtime **T){
  free(*T);
}

void lerDuendes(TADduende *D, int qtd){
  int i;
  for(i = 0; i <qtd; i++){
    scanf("%s", D[i].nome);
    scanf("%d", &D[i].idade);
    D[i].escalado = 0;
  }
}

void escalarTimes(TADduende *D, TADtime *T, int qtd){
  int i; 
  int indice = 0;
  for (i=0; i<(qtd/3); i++)
  {
    indice = proximoMaisVelho(D, qtd);
    D[indice].escalado = 1;
    strcpy(T[i].lider, D[indice].nome);
    T[i].idadeLider = D[indice].idade;
  }
  for (i=0; i<(qtd/3); i++)
  {
    indice = proximoMaisVelho(D, qtd);
    D[indice].escalado = 1;
    strcpy(T[i].entregador, D[indice].nome);
    T[i].idadeEntregador = D[indice].idade;
  }
  for (i=0; i<(qtd/3); i++)
  {
    indice = proximoMaisVelho(D, qtd);
    D[indice].escalado = 1;
    strcpy(T[i].piloto, D[indice].nome);
    T[i].idadePiloto = D[indice].idade;
  }
}

int proximoMaisVelho(TADduende *D, int qtd){
  int indice = 0;
  int maiorIdade = 0;
  for(int i = 0; i < qtd; i++){
    if(D[i].idade > maiorIdade && D[i].escalado == 0){
      indice = i;
      maiorIdade = D[i].idade;
    }
  }
  return indice;
}

void printTimes(TADtime *T, int qtd){
  for(int i = 0; i < qtd; i++){
    printf("Time %d\n%s %d\n%s %d\n%s %d\n\n", (i+1), T[i].lider, T[i].idadeLider, T[i].entregador, T[i].idadeEntregador, T[i].piloto, T[i].idadePiloto);
  }
}
