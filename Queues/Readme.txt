
           made at one end ("REAR") and all removals and
           any access is generally done at the other end ("FRONT").
   (c) Bank Queue.
  - InsertQueue(Q,x): Insert the element x at the end of the queue Q.
  - RemoveQueue(Q): Removes the first element from the queue Q.
  - ReturnFront(Q): Returns the element that is at the beginning (Front) of the Q queue.
  - QueueIsEmpty(Q): Returns true if queue Q is empty, or false otherwise.
interconnected by one-way roads. The connections between cities
are represented by a matrix A as follows:: 
That we must go through to get from c to j. Given a city c, we want to
know how far c is from each of the other cities. The distances
will be stored in a vector d: the distance from c to j will be d[j]. If
it is impossible to get from c to j, we have d[j] = -1. For any c,
d[c] = 0. In the example above with c = 3 we will have d = 2 2 1 0 1 -1.

Algorithm idea: Keep a queue of active cities. A city j is
active if we already know how to get to j but have not yet verified what other
cities we can reach from j. Every time we find a new
active city, we put it at the end of the queue (REAR).


  We have several alternatives:

  1. The start of the queue is always at position 0.
     Inserts are simple. To remove an element,
     all elements must be shifted.

  2. The end of the queue is always at position 0.
     Removals are simple. To insert an element,
     all elements must be shifted.

  3. The start and end of the queue are movable.
              Consider a queue in a 3-position vector.
              We insert elements 1, 2 and 3. After the insertions,
              rear = 2 and front = 0. We remove three elements.
              rear = 2 and front = 3. Queue is empty, but rear = MAX-1
              and it is not possible to insert more elements. 
  
   There are two cases where 'front = (rear + 1) % MAX':
    - When the queue is empty;
    - When the queue is completely full.

   We solved this using 'empty'.
   Or: - save the queue size.
       - always leave one position free, i.e. the queue can only have
          MAX-1 elements.
          The program reads an array representing roads
            between cities in a file, asks the user to choose the city
            of origin and prints the vector d with the distances from the chosen city
            for all others.