#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "STSEG.h"

int main(){
    int t;
    printf("Digite o tamanho da Pilha:\n");
    scanf("%d",&t);
  stack *st;
  st = stack_create(t);

  struct aluno a,b,c;
  
    a.nome='c';  
    b.nome='d'; 
    c.nome='z'; 
  
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
  if (stack_pop(st)==OUT_OF_MEMORY){
      printf("Erro! falta de memória\n");
  }
  stack_print(st);
  printf("Tamanho da pilha: %d",stack_size(st));

}