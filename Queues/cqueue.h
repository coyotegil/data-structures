#define MAX 100

typedef int ElementType;

typedef struct _CircularQueue{
    int  front;  /* First filled position of the queue */
    int  rear;   /* Last filled position of the queue */
    int  empty;  /* empty = 1 if the Queue is empty */
    ElementType elements[MAX];
   } CircularQueue;

void RemoveCircularQueue(ElementType *x, CircularQueue *Q);
void InitializeQueue(CircularQueue *Q);
void InsertQueue(ElementType *x, CircularQueue *Q);
int ReturnFront(CircularQueue *Q);
int FilaVazia(CircularQueue *Q);
void underflow();
void overflow();


