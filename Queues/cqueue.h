#define MAX 100

typedef int TipoDoElemento;

typedef struct _FilaCircular{
    int inicio; /* primeira posi��o cheia */
    int  fim;   /* �ltima posi��o cheia */
    int  vazia; /* vazia = 1 se Fila vazia */
    TipoDoElemento elementos[MAX];
   } FilaCircular;

void RemoveFilaCircular(TipoDoElemento *x, FilaCircular *F);
void InicializaFila(FilaCircular *F);
void InsereFila(TipoDoElemento *x, FilaCircular *F);
int BuscaInicio(FilaCircular *F);
int FilaVazia(FilaCircular *F);
void underflow();
void overflow();


