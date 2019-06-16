/************************************
*       Stack using array           *
*       by Matheus Deodato          *
*************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int stack[200];
    int index; 
}Stack;

Stack* initStack(){
    Stack *S = (Stack*)malloc(sizeof(Stack));
    S->index = 0;
    return S;
}

void push(Stack *P, int V){
    P->stack[P->index++]=V;
}

int pop(Stack *P){
    return P->stack[--P->index];
}

int main(){
    Stack *P = initStack();    
  
    for(int i = 0; i < 30; i++)    push(P,i);
    
    for(int i = 0; i < 30; i++)    printf("%d\n", pop(P));
        
    return 0;
}