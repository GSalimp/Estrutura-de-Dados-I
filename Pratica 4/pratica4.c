#include "pilha.h"
#include <stdio.h>

int main() {
    char ch;
    TItem item;
    TPilha pilha;

    TPilhaInicia(&pilha);

    while (scanf("%c", &ch)!=EOF) {
        if(ch == '('){
            item = ch;
            TPilhaPush(&pilha, item);
        }

        else if(ch == ')'){
            if(TPilhaEhVazia(&pilha) == 0){
                TPilhaPop(&pilha, &item);
            }
        
            else{    
                item = ch;
                TPilhaPush(&pilha, item);
                break;
            }
        }
    }

    //determinar o resultado
    if(TPilhaEhVazia(&pilha) == 1)
        printf("correto\n");
    else
        printf("incorreto\n");

    TPilhaEsvazia(&pilha);

    return 0;//nao remova
}
