#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Fila_EST.h"

int main()
{

struct aluno a,b,c;
  
  strcpy(a.nome,"Joao");
  a.matricula = 123;
  a.n1 = a.n2 = a.n3 =0;

 strcpy(b.nome,"Maria");
  b.matricula = 124;
  b.n1 = b.n2 = b.n3 =10;

  strcpy(c.nome,"jose");
  c.matricula = 125;
  c.n1 = c.n2 = c.n3 =10;

  Dqueue *queue;
  queue = newqueue();
 
  if (queue_push_front(queue, a)==OUT_OF_MEMORY){
      printf("Erro! falta de memória\n");
  }
  
  if (queue_push_front(queue, b)==OUT_OF_MEMORY){
      printf("Erro! falta de memória\n");
  }
    queue_pop_back(queue);
     queue_pop_back(queue);
  if (queue_push_front(queue, c)==OUT_OF_MEMORY){
      printf("Erro! falta de memória\n");
  }
    
  queue_print(queue);
}