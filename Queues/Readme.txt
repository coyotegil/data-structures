Queue: It's a linear list where all insertions are
           made at one end ("REAR") and all removals and
           any access is generally done at the other end ("FRONT").              ____________________removals  -> |_|_|____________|_|_| <- inserts                                  ”                  ”           (FRONT)            (REAR)                 The queue is a FIFO (First In First Out) structure.  Ex.:     (a) Train parking;   (b) Multiprogramming systems;
   (c) Bank Queue.Queue as an abstract data typeNecessary operations:  - InitializeQueue(Q): Makes an empty queue Q.
  - InsertQueue(Q,x): Insert the element x at the end of the queue Q.
  - RemoveQueue(Q): Removes the first element from the queue Q.
  - ReturnFront(Q): Returns the element that is at the beginning (Front) of the Q queue.
  - QueueIsEmpty(Q): Returns true if queue Q is empty, or false otherwise.Example: Imagine 6 cities numbered from 0 to 5 that are
interconnected by one-way roads. The connections between cities
are represented by a matrix A as follows::        A[i][j] == 1  if there is a road from city i to city j        A[i][j] == 0  otherwise.Example:           +---------------+                   |  | 0 1 2 3 4 5|          +--+------------+          |0 | 0 0 0 0 0 0|          |1 | 1 0 0 0 0 0|           |2 | 0 1 0 0 0 0|           |3 | 0 0 1 0 1 0|           |4 | 1 0 0 0 0 0|          |5 | 0 1 0 0 0 0|             +---------------+                             The distance from city c to city j is the smallest number of roads
That we must go through to get from c to j. Given a city c, we want to
know how far c is from each of the other cities. The distances
will be stored in a vector d: the distance from c to j will be d[j]. If
it is impossible to get from c to j, we have d[j] = -1. For any c,
d[c] = 0. In the example above with c = 3 we will have d = 2 2 1 0 1 -1.

Algorithm idea: Keep a queue of active cities. A city j is
active if we already know how to get to j but have not yet verified what other
cities we can reach from j. Every time we find a new
active city, we put it at the end of the queue (REAR).     j = 0;   While j < 6       d[j] = -1;       j = j + 1;   d[c] = 0;      Insert(Q, c)   While !Empty(Q)      i = ReturnFront(Q);      Remove(Q);      j = 0;      While j < 6         If (A[i][j] == 1 and d[j] == -1)             d[j] = d[i] + 1;            Insert(F, j);         j = j+1;Queue Representation in a Vector


  We have several alternatives:

  1. The start of the queue is always at position 0.
     Inserts are simple. To remove an element,
     all elements must be shifted.

  2. The end of the queue is always at position 0.
     Removals are simple. To insert an element,
     all elements must be shifted.

  3. The start and end of the queue are movable.      -1 0_1____________________(MAX - 1)   |_|_|__________________|_|          QUEUE (initialization)   front = 0   rear = -1   front := indicates the position of the last element removed from the queue   rear  := indicates the position of the last inserted element in the queue -1 0_1_______i_____________f_____(MAX - 1)   |_|_|_____|X|X|X|...|X|X|X|____|_|          QUEUE (general case)   front = i  rear  = f Overflow occurs when inserting in rear  = MAX - 1 Underflow occurs when removing in front = rear + 1Disadvantage: we may overflow with an empty queue!
              Consider a queue in a 3-position vector.
              We insert elements 1, 2 and 3. After the insertions,
              rear = 2 and front = 0. We remove three elements.
              rear = 2 and front = 3. Queue is empty, but rear = MAX-1
              and it is not possible to insert more elements.                                            In C:#define _MAX_ ...typedef ... ElementTypetypedef struct {                 int front, rear;                 ElementType elements[_MAX_];               } QueueType;/* Procedure to insert an element x into the queue */void InsertQueue(ElementType x, QueueType *Q) {  Q->rear++;  if( Q->rear == _MAX_ )     Overflow(); /* The rear has reached the last position of the vector */  else       Q->elements[Q->rear] = x;}/* Procedure to remove an element from the queue */void Remove(QueueType *Q) {  if( Q->rear < Q->front ){     printf("Underflow");     exit(1);    } /* The queue is empty */  else      Q->front++;} - Circular Queue                   0           (MAX -1)                   _____________Circular Queue -> |x|...|_|x|x|x|       General Case                   ”     ”                     rear  front  In C:#define MAX ...typedef ... ElementType;typedef struct{    int front; /* First filled position */    int rear;   /* Last filled position */     int empty; /* empty = 1 if Queue is empty */    ElementType elements[MAX];   } CircularQueue;void RemoveCircularQueue(CircularQueue *Q) {  if(Q->empty == 1 )    Underflow();  else {     Q->front = (Q->front + 1) % MAX;    if (Q->front == (Q->rear + 1) % MAX)        Q->empty = 1;   }}What is the use of 'empty'?
  
   There are two cases where 'front = (rear + 1) % MAX':
    - When the queue is empty;
    - When the queue is completely full.

   We solved this using 'empty'.
   Or: - save the queue size.
       - always leave one position free, i.e. the queue can only have
          MAX-1 elements.Use case: Implementation of a circular queue with its basic operations.
          The program reads an array representing roads
            between cities in a file, asks the user to choose the city
            of origin and prints the vector d with the distances from the chosen city
            for all others.            