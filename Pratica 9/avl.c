#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void TAVLInicia (TNo **pRaiz) {
    *pRaiz = NULL;
}

// Manter como especificado
int TAVLInsere (TNo **ppRaiz, TItem *x) {
  if(* ppRaiz == NULL) {
    *ppRaiz = (TNo*) malloc(sizeof(TNo));
    (*ppRaiz)->item = *x;
    (*ppRaiz)->pEsq = NULL;
    (*ppRaiz)->pDir = NULL ;
    return 1;
  }else if(compara(*x, (*ppRaiz)->item) == PRIMEIRO_MAIOR) { // (*ppRaiz)->item.chave > x->chave 
    if (TAVLInsere(&(*ppRaiz )->pEsq, x )) {
      if(TAVLBalanceamento(ppRaiz))
        return 0;
      else
        return 1;
    }
  }else if(compara(*x, (*ppRaiz)->item) == PRIMEIRO_MENOR ) { // (*ppRaiz)->item.chave < x->chave
    if (TAVLInsere(&(*ppRaiz)->pDir, x)) {
      if (TAVLBalanceamento(ppRaiz))
        return 0;
      else
        return 1;
  }else
    return 0;
  }else
    return 0;

  return 1;
}

// Manter como especificado
TNo *TNoCria (TItem x) {
  TNo *pAux = (TNo*) malloc (sizeof (TNo));
  
  pAux -> item = x;
  pAux -> pEsq = NULL ;
  pAux -> pDir = NULL ;
  
  return pAux ;
}

ENUM_RESPOSTA compara(const TItem item1, const TItem item2) {
  if(strcmp(item1.chave, item2.chave) > 0)
    return PRIMEIRO_MENOR;
  if(strcmp(item1.chave, item2.chave) < 0)
    return PRIMEIRO_MAIOR;
  
  return IGUAIS;
}

int TAVLFB (TNo *pRaiz) {
  if ( pRaiz == NULL )
    return 0;
  
  return TAVLAltura(pRaiz -> pEsq ) - TAVLAltura(pRaiz -> pDir );
  
  return 1;
}

int TAVLAltura (TNo *pRaiz) {
  int iEsq , iDir ;

  if ( pRaiz == NULL )
    return 0;

  iEsq = TAVLAltura (pRaiz -> pEsq );
  iDir = TAVLAltura (pRaiz -> pDir );

  if ( iEsq > iDir )
    return iEsq + 1;
  else
    return iDir + 1;

}

void CaminhamentoPreOrdem (TNo *pRaiz){
  if (pRaiz == NULL)
    return;
  
  printf ("%s\n", pRaiz->item.chave );
  
  CaminhamentoPreOrdem (pRaiz->pEsq );
  CaminhamentoPreOrdem (pRaiz->pDir );
}

// Funções para rotação da árvore AVL
// Manter como especificado todas as funções abaixo
void TAVLRSE (TNo **ppRaiz) {
  TNo * pAux;
  pAux = (*ppRaiz)->pDir;
  (*ppRaiz)->pDir = pAux->pEsq;
  pAux->pEsq = (*ppRaiz);
  (*ppRaiz) = pAux;
}

// Manter como especificado
void TAVLRSD (TNo **ppRaiz) {
  TNo * pAux;
  pAux = (*ppRaiz)->pEsq;
  (*ppRaiz)->pEsq = pAux->pDir;
  pAux->pDir = (*ppRaiz);
  (*ppRaiz) = pAux;
}

// Manter como especificado
int TAVLBalancaEsquerda (TNo **ppRaiz) {
  int fbe = TAVLFB((*ppRaiz)->pEsq);
  if ( fbe >= 0 ) {
    TAVLRSD ( ppRaiz ) ;
    return 1;
  } else {
    /* Rotação Dupla Direita */
    TAVLRSE (&((*ppRaiz)->pEsq) );
    TAVLRSD (ppRaiz) ;
    return 1;
  }
}

// Manter como especificado
int TAVLBalancaDireita (TNo **ppRaiz) {
  int fbd = TAVLFB((*ppRaiz)-> pDir);
  if (fbd <= 0) {
    TAVLRSE(ppRaiz );
    return 1;
  } else {
    /* Rotação Dupla Esquerda */
    TAVLRSD (&((*ppRaiz)->pDir) );
    TAVLRSE (ppRaiz) ;
    return 1;
  }
 return 0;
}

// Manter como especificado
int TAVLBalanceamento (TNo ** ppRaiz) {
  int fb = TAVLFB (*ppRaiz);
  if ( fb > 1)
    return TAVLBalancaEsquerda (ppRaiz) ;
  else if ( fb < -1 )
    return TAVLBalancaDireita (ppRaiz);
  else
    return 0;
}
