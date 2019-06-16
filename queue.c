/************************************
*    Circular Queue using array     *
*       by Matheus Deodato          *
*************************************/
#include <stdio.h>
#include <stdlib.h>

#define SIZE_QUEUE  10

typedef struct{
    int queue[SIZE_QUEUE];
    int head, tail, full; 
}Queue;

Queue* initQueue(){
    Queue *S = (Queue*)malloc(sizeof(Queue));
    S->head = 0;
    S->tail = 0;
    S->full = 0;
    return S;
}

int queue_insert(Queue *P, int V){
    int N = (P->tail+1)%(SIZE_QUEUE);
    
    if (!P->full) {
        if(N == P->head && P->head!=P->tail){ //if the queue is full
            P->full=1;                   
        }
        P->queue[P->tail] = V;
        P->tail = N;        
        return 1; //Inserted
    }
    return 0; // Queue is full    
}

int queue_remove(Queue *P){   
    if(P->tail == P->head && !P->full){ //If the queue is empty
            return -__INT_MAX__;
    }   
    if (P->full) //if the queue is full, then its not full now
        P->full = 0;
            
    int V = P->queue[P->head];
    P->head = (P->head+1)%SIZE_QUEUE;
    return V;
}

int main(){
    Queue *P = initQueue();    
    printf("INSERT\n");
    for(int i = 0; i < 12; i++)  queue_insert(P,i)?printf("%d Inserted\n", i):printf("Queue is FULL\n");               
    
    printf("REMOVE\n");
    for(int i = 0; i < 12; i++){   
        int r = queue_remove(P);
        r == -__INT_MAX__?printf("Queue is empty\n"):printf("%d Removed\n", r);
    }
    return 0;
}