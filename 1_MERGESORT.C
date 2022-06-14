#include <stdio.h>
#include <stdlib.h> /* Used to fillup the vector with random values */
#define MAX 100


/* Function that fills up a vector with random values */
void fillup(int v[], int n);

/* Function that performs the merge and sort in a given vector */
void mergesort (int p, int r, int v[]);

/* Fuction that inserts a value in the vector in a given position */
void inset(int p, int q, int r, int v[]);

//void selection (int n, int v[]);


int main(){
	int n, v[100], i;

	printf("Type the lenght of the vector: ");
	scanf("%d", &n);
	fillup(v, n);

	for(i= 0; i<n; i++){
		printf(" %d", v[i]);
	}
	printf("\n");

	mergesort (0,n,v);


	for(i= 0; i<n; i++){
		printf(" %d", v[i]);
	}
	printf("\n");

	return 0;
}


void fillup(int v[], int n){
	int i;
	srand(0);
	for (i=0;i<n;i++)
		v[i]=rand()%MAX;
}


void mergesort (int p, int r, int v[]) {
	int q;
	if (p < r-1) {
		q = (p + r)/2;
        mergesort (p, q, v);
        mergesort (q, r, v);
        inset (p, q, r, v);


      }
}


void inset(int p, int q, int r, int v[]){
	int i, j, k, w[100];

	i = p;
	j = q;
	k = p;

	while((i<q)&&(j<r)){
		if(v[i] < v[j]){
			w[k] = v[i];
			i = i+1;
		}
		else{
			w[k] = v[j];
			j = j+1;
		}
		k = k+1;
	}

	/* Copies the remaining piece of a vector */

	if(i<q)
		for(; i<q; i++){
			w[k] = v[i];
			k = k+1;
		}

	if(j<r)
		for(; j<r;j++){
			w[k] = v[j];
			k = k+1;
		}

   k = p;

	while(k<r){
		v[k] = w[k];
		k = k+1;
	}

}