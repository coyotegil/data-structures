#define MAX 100
#include <stdio.h>
#include "cqueue.h"

int main(){
	int n,j,i,c,u;
	int A[MAX][MAX];
	int d[MAX];
	CircularQueue Q;

	FILE *f;
	f=fopen("input.dat","r");

	fscanf(f,"%d",&n);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		   fscanf(f," %d",&A[i][j]);
		}
	}

	for(u=0;u<n;u++){
		d[u] = -1;
	}

	printf("Type in the number of the city: ");
	scanf("%d",&c);
	c--;
	d[c]=0;

	InitializeQueue(&Q);
	InsertQueue(&c,&Q);

	while(!QueueIsEmpty(&Q)){
		RemoveCircularQueue(&i,&Q);
		j=0;
		while(j<n){
			if(A[i][j] == 1 && d[j] == -1){
				d[j] = d[i] + 1;
				InsertQueue(&j,&Q);
			}
			j = j+1;
		}
	}
	for(i=0;i<n;i++) printf("%d ",d[i]);

	return 0;

}

