#include "ordenacao.h"
#include <stdlib.h>

//Manter como especificado
struct time *alocaVetor(int n){
    struct time *vetor;
    vetor = (struct time*) calloc(n, sizeof(struct time));
    return vetor;

}

//Manter como especificado
void desalocaVetor(struct time **vetor){
    free((*vetor));
}

//implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare
void ordenacao(struct time *vetor, int n){
    int h = 1;
    int i, j;
    struct time aux;
    while(h < n){
        h= (h *3) + 1;
    }
    do{
        h = (h-1)/3;
        for(int i = h; i < n; i ++){
            aux = vetor[i];
            int j = i - h;
            while(j >= 0 && compare(aux, vetor[j]) == 1){
                vetor[j+h] = vetor[j];
                j = j-h;
            }
            vetor[j+h] = aux;
        }
    }while(h != 1);
}

//compara dois elementos do vetor de times, indicado se o metodo de ordenacao deve troca-los de lugar ou nao
int compare(const struct time t1, const struct time t2){
    if(t1.pontosCamp > t2.pontosCamp)
        return 1;
    else if(t2.pontosCamp > t1.pontosCamp)
        return 0;
    else if(t1.pontosCamp == t2.pontosCamp){
        if(t1.saldo > t2.saldo)
            return 1;
        else if(t2.saldo > t1.saldo)
            return 0;
        else if(t2.saldo == t1.saldo){
            if(t1.marcados > t2.marcados)
                return 1;
            else if(t2.marcados > t1.marcados)
                return 0;
            else if(t1.marcados == t2.marcados){
                if(t1.inscricao < t2.inscricao)
                    return 1;
                else if(t1.inscricao > t2.inscricao)
                    return 0;
            }
        }
    }
}
void preencheVetor(struct time *vetor, int time1, int time2, int pontos1, int pontos2){
    vetor[time1-1].inscricao = time1;
    vetor[time2-1].inscricao = time2;
    vetor[time1-1].marcados += pontos1;
    vetor[time1-1].levados += pontos2;
    vetor[time2-1].marcados += pontos2;
    vetor[time2-1].levados += pontos1;
    float aux1 = vetor[time1-1].marcados;
    float aux2 = vetor[time1-1].levados;
    vetor[time1-1].saldo = aux1/aux2;
    aux1 = vetor[time2-1].marcados;
    aux2 = vetor[time2-1].levados;
    vetor[time2-1].saldo = aux1/aux2;
    if(pontos1 > pontos2){
        vetor[time1 -1].pontosCamp += 2;
        vetor[time2-1].pontosCamp += 1;
    }
    else{
        vetor[time1 -1].pontosCamp += 1;
        vetor[time2-1].pontosCamp += 2;
    }
}
