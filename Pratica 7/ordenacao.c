#include "ordenacao.h"
#include <stdlib.h>
#include <string.h>

void ordena(TLista *pLista) {
	TCelula *frente = pLista->pPrimeiro;
	TCelula *tras = NULL;

	while (frente != NULL){
		tras = frente->pProx;
		while (tras != NULL && tras->pPrev != NULL && compare(tras->item, tras->pPrev->item) < 0){
			troca(tras, tras->pPrev);
			tras = tras->pPrev;
		}
		frente = frente->pProx;
	}
}

int compare(const TAluno t1, const TAluno t2) {
    return(strcmp(t1.nome, t2.nome));
}

void troca(TCelula *primeiro, TCelula *secundo){
	TCelula value;
	value.item = primeiro->item;
	primeiro->item = secundo->item;
	secundo->item = value.item;
}
