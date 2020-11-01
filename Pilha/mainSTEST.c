#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "STEST.h"

int main(){
  

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

  stack *st;
  st = stack_create();
  if (stack_empty(st)==SUCCESS){
      printf("Pilha Vazia!\n");
  }
  if (stack_push(st, a)==OUT_OF_MEMORY){
      printf("Erro! falta de memória\n");
  }
  if (stack_push(st, b)==OUT_OF_MEMORY){
      printf("Erro! falta de memória\n");
  }
  if (stack_push(st, c)==OUT_OF_MEMORY){
      printf("Erro! falta de memória\n");
  }
  if (stack_pop(st)!=SUCCESS){
      printf("Erro! falta de memória\n");
  }
  stack_print(st);
  printf("Tamanho da pilha: %d",stack_size(st));

}