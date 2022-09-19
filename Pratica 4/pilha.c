#include "pilha.h"

// Inicia as variaveis da lista
int TPilhaInicia(TPilha *pPilha) {
    return TListaInicia(pPilha);
}

//Retorna se a lista esta vazia
int TPilhaEhVazia(TPilha *pPilha) {
    return TListaEhVazia(pPilha);
}

// Insere um item no final da lista
int TPilhaPush(TPilha *pPilha, TItem item) {
    return TListaInserePrimeiro(pPilha, item);
}

// Retira o primeiro item da lista
int TPilhaPop(TPilha *pPilha, TItem *pItem) {
    return TListaRetiraPrimeiro(pPilha, pItem);
}

//Remove cada elemento de uma lista e libera a memória
void TPilhaEsvazia(TPilha *pPilha) {
    return TListaEsvazia(pPilha);
}