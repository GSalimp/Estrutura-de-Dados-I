#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
int TListaInicia(TLista *pLista) {
    pLista->pCabeca = (TCelula*) malloc(sizeof(TCelula));
    if(pLista->pCabeca == NULL)
        return 0;
    pLista->pCabeca->pProx = NULL;
    return 1;
}

//Retorna se a lista esta vazia
int TListaEhVazia(TLista *pLista) {
    if(pLista->pCabeca->pProx == NULL)
        return 1;

    return 0;
}

// Insere um item no inicio da lista
int TListaInserePrimeiro(TLista *pLista, TItem item) {
    TCelula *new = malloc(sizeof(TCelula));
    
    if(new == NULL)
        return 0;
    
    new->item = item;
    new->pProx = pLista->pCabeca->pProx;
    pLista->pCabeca->pProx = new;
    
    return 1; 
}

// Retira o primeiro item da lista
int TListaRetiraPrimeiro(TLista *pLista, TItem *pItem) {
    if(TListaEhVazia(pLista))
        return 0;
    
    TCelula *pAux;
    pAux = pLista->pCabeca->pProx;
    *pItem = pAux->item;
    pLista->pCabeca->pProx = pAux->pProx;
    
    free(pAux);
    return 1;
}

// Imprime os elementos da lista
void TListaImprime(TLista *pLista) {
    printf("Olá\n");
}

//Remove cada elemento de uma lista e libera a memória
void TListaEsvazia(TLista *pLista) {
    TCelula *aux;

    while(pLista->pCabeca->pProx != NULL){
        aux = pLista->pCabeca->pProx;
        pLista->pCabeca->pProx = aux->pProx;
        free(aux);
    }

    free(pLista->pCabeca);
}
