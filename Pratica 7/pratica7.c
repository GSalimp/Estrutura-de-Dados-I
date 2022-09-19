#include "ordenacao.h"
#include <stdio.h>

int main ()
{
	int n, k;
	TLista lista;
	TAluno aluno;

	// ler as quantidades
	scanf("%d %d", &n, &k);
	
	// criar a lista encadeada
	TListaCria(&lista);

	// preencher a lista encadeada
	for (int i = 0; i < n; i++){
		scanf("%s", aluno.nome);
		TListaInsereInicio(&lista, aluno);
	}
	
	// ordenar a lista
	ordena(&lista);

	//imprimir o resultado
	TListaImprimeValor(&lista, k, n);
	
	
	// desalocar o vetor
	TListaDestroi(&lista);

  	return 0;
}
