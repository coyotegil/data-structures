#include <stdlib.h>
#include "cqueue.h"
#include <stdio.h>
#define MAX 100

typedef int TipoDoElemento;

//typedef struct _FilaCircular{
//    int inicio; /* primeira posi��o cheia */
//    int  fim;   /* �ltima posi��o cheia */
//    int  vazia; /* vazia = 1 se Fila vazia */
//    TipoDoElemento elementos[MAX];
//   } FilaCircular;


void RemoveFilaCircular(TipoDoElemento *x, FilaCircular *F) {

  if(F->vazia == 1 )
    underflow();
  else {
    *x = F->elementos[F->inicio];
    F->inicio = (F->inicio + 1) % MAX;
    if (F->inicio == (F->fim + 1) % MAX)
       F->vazia = 1;
  }
}

void InicializaFila(FilaCircular *F){
	F->inicio = 1;
	F->fim = 0;
	F->vazia =1;
}

void InsereFila(TipoDoElemento *x, FilaCircular *F){
	F->fim = (F->fim+1)% MAX ;
	if(((F->fim)% MAX == F->inicio) && F->vazia==0){
		overflow();
		F->fim--;
	}
	else{
		F->elementos[F->fim] = *x;
		F->vazia=0;
	}
}

int BuscaInicio(FilaCircular *F){
	return F->elementos[F->inicio];
}

int FilaVazia(FilaCircular *F){
	if (F->vazia ==1) return 1;
	else return 0;
}

void overflow(){
	printf("Capacidade da fila ultrapassada !!");
	exit(1);
}

void underflow(){
  printf("Underflow");
  exit(1);
}



