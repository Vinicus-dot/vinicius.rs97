#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_encadeada.h"

int main(){

  printf("Informe se a lista eh ordenada ou nao, 0 para nao e 1 para sim!\n Se digitar diferente das opcoes sua lista esta errada!!");
  int n;
  scanf("%d",&n);
  Lista *alunos_ic;
  alunos_ic = cria_lista(n);

  struct aluno a;
  a.n1 = a.n2 = a.n3 = 0;

  a.matricula = 16;
  strcpy(a.nome,"HENRI");
  int ret = list_insert_sorted(alunos_ic, a);
  if (ret == -1){
    printf("ERRO!");
  }
  if (ret == -4){
    printf("ERRO de lista normal!");
  }
  list_print(alunos_ic);

  a.matricula = 11;
  strcpy(a.nome,"HENRIQUEZERA");
  ret = list_push_pos(alunos_ic,1 ,a);
  if (ret == -1){
    printf("ERRO!");
  }
   if (ret == -2){
    printf("ERRO! posicao nao encontrada");
  }
  if (ret == -4){
    printf("ERRO de lista ordenada!");
  }
  list_print(alunos_ic);

   a.matricula = 10;
  strcpy(a.nome,"HENRIQUA");
  ret = list_push_back(alunos_ic, a);
  if (ret == -1){
    printf("ERRO!");
  }
  if (ret == -4){
     printf("ERRO de lista ordenada!");
  }
  list_print(alunos_ic);

  a.matricula = 14;
  strcpy(a.nome,"ZERA");
  ret = list_push_pos(alunos_ic,3 ,a);
  if (ret == -1){
    printf("ERRO!");
  }
  if (ret == -4){
     printf("ERRO de lista ordenada!");
  }
  list_print(alunos_ic);

  struct aluno b;
  if (list_get_pos(alunos_ic, 1, &b) == 0){
    printf("\n%s\n", b.nome);
  }
  else
  {
    printf("erro!");
  }
  if (list_get_mat(alunos_ic, 16, &b) == 0){
    printf("\n%s\n", b.nome);
  } 


  
  return 0;
}

