#include <stdio.h>
#include <string.h>

#include "tadseg.h"

int main(void) {
  printf("Hello World\n");
    
  Lista *alunos_ic;
  alunos_ic = cria_lista(2);

  struct aluno a;
  a.matricula = 10;
  strcpy(a.nome,"Ana Maria Braga");
  a.n1 = a.n2 = a.n3 = 0;

  int ret;
  
  ret = inserirnapo(alunos_ic,2,a);
  if (ret == -1){
    printf("ERRO!");
  }
  
  a.matricula = 11;
  strcpy(a.nome,"HENRIQUEZERA");
  ret = insere_lista_ordenada(alunos_ic, a);
  if (ret == -1){
    printf("ERRO!");
  }
  
   a.matricula = 16;
  strcpy(a.nome,"HENRI");
  ret = insere_lista_final(alunos_ic, a);
  if (ret == -1){
    printf("ERRO!");
  }
  imprime_lista(alunos_ic);
  remove_lista_otimizado(alunos_ic ,16);// testando se removel esta ok 
  
   
  if (lista_cheia(alunos_ic) == 0){
    printf("Lista cheia \n");
  } 
  else
  {
    printf("Lista Com espaco\n");
  }
  alunos_ic=compactarL(alunos_ic);
  
  
  if (lista_cheia(alunos_ic) == 0){
    printf("Lista cheia \n");
  } 
  else
  {
    printf("Lista Com espaco\n");
  }


  
    a.matricula = 12;
  strcpy(a.nome,"KUFARIA");
  ret = insere_lista_inicio(alunos_ic, a);
  if (ret == -1){
    printf("ERRO!");
  }
 
    struct aluno b;  //46 bytes
  if (consulta_lista_mat(alunos_ic, 12, &b) == 0){
    printf("\n%s\n", b.nome);
  } 
  if (remove_lista(alunos_ic, 12) == 0){
    printf("Removido\n");
  } 
  if (consulta_lista_pos(alunos_ic, 3, &b) == 0){
    printf("\n%s\n", b.nome);
  }
  if (remove_lista_inicio(alunos_ic) == 0){
    printf("Removido a primeira posicao\n");
  } 
  if (remove_lista_final(alunos_ic) == 0){
    printf("Removido na ultima posicao\n");
  } 
   
  printf("Tamanho da lista eh:%d\n",tamanho_lista(alunos_ic));
  
   
   
    if (lista_vazia(alunos_ic) == 0){
    printf("Lista Vazia \n");
  } 
  else
  {
    printf("Lista tem pelo menos 1 valor na lista\n");
  }
  
  
  //imprime_lista(alunos_ic);
  //alunos_ic=compactarL(alunos_ic);
  return 0;
}