#include "ordenacao.h"
#include <stdio.h>

int main()
{
    int inst = 1;
    //enquanto houver dados
    while (1) {
        int n;
        int time1, time2, pontos1, pontos2;
        int i, npartidas;
        struct time *vetor = NULL;

        //leia o numero de times
        scanf("%d", &n);

        //se for zero, o programa acaba
        if(n == 0)
            return 0;
        //aloque o vetor
        vetor = alocaVetor(n);
        //calcula o numero de partidas
        npartidas = n * (n - 1) / 2;

        //para cada partida...
        for (i = 0; i < npartidas; ++i) {
            scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);

            //preencher o vetor de estruturas de acordo com os dados lidos
            preencheVetor(vetor, time1, time2, pontos1, pontos2);
            for(int i = 0; i < n; i++){
                if(vetor[i].levados == 0){
                    vetor[i].saldo = vetor[i].marcados;
                }
            }
        }

        //ordenar os times
        ordenacao(vetor, n);
        if(inst != 1)
            printf("\n\n");
        //imprima o resultado
        printf("Instancia %d\n", inst);
        for(int i = 0; i < n; i++){
            printf("%d ", vetor[i].inscricao);
        }

        //desaloque o vetor
        desalocaVetor(&vetor);
        inst++;
    }

    return 0;
}
