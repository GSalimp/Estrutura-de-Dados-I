# ifndef ordenacao_h
# define ordenacao_h

typedef struct{
	char nome [20];
	int chamada;
} TipoAluno;

//Manter como especificado
void Heapsort(TipoAluno*, int);

void heapRefaz(TipoAluno *alunos, int esq, int dir);

int compare(char *nome1, char *nome2);

void heapConstroi(TipoAluno *alunos, int n);

//Manter como especificado
TipoAluno *alocaAlunos(int);

//Manter como especificado
void desalocaAlunos(TipoAluno**);

# endif
