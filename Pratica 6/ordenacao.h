# ifndef ordenacao_h
# define ordenacao_h

struct time{
    int inscricao;
    int pontosCamp;
    int levados;
    int marcados;
    float saldo; 
};

//Manter como especificado
void ordenacao(struct time *vetor, int n);
//Manter como especificado
struct time *alocaVetor(int n);
//Manter como especificado
void desalocaVetor(struct time **vetor);
//faz a comparacao utilizada para ordenar os times
int compare(struct time t1, struct time t2);
void preencheVetor(struct time *vetor, int time1, int time2, int pontos1, int pontos2); 
# endif
