#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno TAluno;

typedef struct turma TTurma;

void lerInfos(int*, char*);

void alocaAluno(TAluno**);

void alocaTurma(TTurma**, int);

void desalocaAluno(TAluno**);

void desalocaTurma(TTurma**);

void lerTurma(TTurma*);

float calcularMetrica(TTurma*, char*, char);

void printMetrica(char*, float, char);

#endif