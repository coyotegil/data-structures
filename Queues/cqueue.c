#include <stdlib.h>
#include "cqueue.h"
#include <stdio.h>
#define MAX 100

typedef int ElementType;

//typedef struct _CircularQueue{
//    int front; /* primeira posi��o cheia */
//    int  rear;   /* �ltima posi��o cheia */
//    int  empty; /* empty = 1 se Fila empty */
//    ElementType elements[MAX];
//   } CircularQueue;


void RemoveCircularQueue(ElementType *x, CircularQueue *Q) {

  if(Q->empty == 1 )
    underflow();
  else {
    *x = Q->elements[Q->front];
    Q->front = (Q->front + 1) % MAX;
    if (Q->front == (Q->rear + 1) % MAX)
       Q->empty = 1;
  }
}

void InitializeQueue(CircularQueue *Q){
	Q->front = 1;
	Q->rear = 0;
	Q->empty =1;
}

void InsertQueue(ElementType *x, CircularQueue *Q){
	Q->rear = (Q->rear+1)% MAX ;
	if(((Q->rear)% MAX == Q->front) && Q->empty==0){
		overflow();
		Q->rear--;
	}
	else{
		Q->elements[Q->rear] = *x;
		Q->empty=0;
	}
}

int ReturnFront(CircularQueue *Q){
	return Q->elements[Q->front];
}

int FilaVazia(CircularQueue *Q){
	if (Q->empty ==1) return 1;
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



