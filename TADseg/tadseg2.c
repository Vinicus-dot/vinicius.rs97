#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tadseg.h" //inclui os Protótipos

 //Definição do tipo lista
 struct lista
 {
 int qtd;
 int MAX;
 int inicio;
 struct aluno *dados;
 };
Lista* cria_lista(int n)
{
     
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));// Aloca minha lista 
    if(li != NULL)
    {    
        li->qtd = 0;//quantidade de elementos na lista
        li->MAX = n;//guarda o valor max da lista em momento de execução
        li->inicio=n;//guarda o valor inicial para realocação futura
    }
    
    li->dados = (Aluno*) malloc(sizeof( Aluno )*n);// aloca a quantidade de alunos vao ser inseridos 
    if (li->dados == NULL){
      libera_lista(li);
      return NULL;
    }
    
    
    return li;
}
void libera_lista(Lista* li)
{
    free(li);//libera o espaço ocupado pela memoria
}
int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
 if (li == NULL)
    return -1;
  if ( (pos <=0) || (pos > li->qtd))
    return -2; // erro de posição inválida
  *al = li->dados[pos-1];// aponta para o ponteiro o valor encontrando assim podendo ser lido na main 
  return 0;
}
int consulta_lista_mat(Lista* li, int mat, struct aluno *al)
{
    if(li == NULL)
        return -1;
    int i = 0;

    while(i<li->qtd && li->dados[i].matricula != mat)// procura a pocisção onde vai ser usado para retornar o valor da consulta
            i++;

    if(i == li->qtd)//elemento nao encontrado
     return -1;

    *al = li->dados[i];// aponta para o ponteiro a posição onde foi encontrada a matricula correspondente
    return 0;
}
int insere_lista_final(Lista* li, struct aluno al)
{

    if(li == NULL)
        return -1;
    if(li->qtd == li->MAX)//lista cheia
    {   
        
        if(li->inicio ==1)
            li->inicio=+2;
         li->dados = (Aluno *)realloc(li->dados ,li->inicio*sizeof(Aluno));// relocando memoria para poder suprir o  usuario
         
         li->MAX +=li->inicio;
    }
    
    li->dados[li->qtd] = al;

    li->qtd++;
    return 0;
}

int insere_lista_inicio(Lista* li, struct aluno al)
{
    if(li == NULL)
        return -1;
     if(li->qtd == li->MAX)//lista cheia
        {   
            if(li->inicio ==1)
                li->inicio=+2;
         li->dados = (Aluno *)realloc(li->dados ,li->inicio*sizeof(Aluno));// relocando memoria para poder suprir o  usuario
         li->MAX +=li->inicio;
        }
 
    for(int i=li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];// movendo todos os dados de alunos para frente para poder ocupar o local 1 o novo al

    li->dados[0] = al;
    li->qtd++;
 
    return 0;
}
int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL)
        return -1;
     if(li->qtd == li->MAX)//lista cheia
    {   
        if(li->inicio ==1)
            li->inicio=+2;
         li->dados = (Aluno *)realloc(li->dados ,li->inicio*sizeof(Aluno));// relocando memoria para poder suprir o  usuario
         li->MAX +=li->inicio;
    }

    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula < al.matricula) // procura a pocisção onde vai começar a ordenação
        i++;

    for(k=li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];

    li->dados[i] = al;
    li->qtd++;
    return 0;
 }
 int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)// procura a pocisção onde vai remover
        i++;
    if(i == li->qtd)//elemento nao encontrado
    return 0;

    for(k=i; k< li->qtd-1; k++)

    li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 0;
}
int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;

    int k = 0;
    for(k=0; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];// aqui move todos os numero sem ser o primeiro 1 casa a tras para poder remover do inicio
 
    li->qtd--;
    return 0;
}
int remove_lista_final(Lista* li){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;

    li->qtd--;//remove do final da lista um valor 
    return 0;
}
int tamanho_lista(Lista* li){
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}
int lista_cheia(Lista* li)
{
    if(li == NULL)
        return -1;
    if(li->qtd == li->MAX)
        return 0;
    return -2;
}

int lista_vazia(Lista* li)
{
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return 0;
    return -2;
}
int imprime_lista(Lista *li){
  if (li == NULL)
    return -1;
  for (int i =0; i < li->qtd; i++)  {
    printf("Matricula: %d\n",li->dados[i].matricula);
    printf("Nome: %s\n",li->dados[i].nome);
    printf("Notas: %.2f, %.2f, %.2f\n",li->dados[i].n1,li->dados[i].n2,li->dados[i].n3);
    printf("-------------------------------\n");
  }
  return 0;
}
int remove_lista_otimizado(Lista* li, int mat){
    if(li == NULL)
        return -1;
    if(li->qtd == 0)
        return -1;
    int i = 0;
    while(i<li->qtd && li->dados[i].matricula != mat)// procura a pocisção onde vai remover
        i++;
    if(i == li->qtd)//elemento nao encontrado
        return 0;

    li->qtd--;
    li->dados[i] = li->dados[li->qtd];
    return 0;
}
Lista* compactarL(Lista* li)
{
   int x=-2, valor=li->qtd;
  
    while (valor != 0)
          {
             x+=1;
              valor = valor / 10;// calculo para padronizar qualquer valor de 2 para cima 
          }
    if(x <0)
        x=0;
    
        
   
    x=ceil(li->qtd/pow(10,x))*pow(10,x);
   
    li->dados = (Aluno *)realloc(li->dados ,x*sizeof(Aluno));// relocando memoria para poder suprir o  usuario
    li->MAX =x;
     
    return li;
}
int inserirnapo(Lista* li, int pos, struct aluno al){
    if (li == NULL)
        return -1;
    if(li->qtd == li->MAX)//lista cheia
    {   
        if(li->inicio ==1)
            li->inicio=+2;
         li->dados = (Aluno *)realloc(li->dados ,li->inicio*sizeof(Aluno));// relocando memoria para poder suprir o  usuario
         li->MAX +=li->inicio;
    }
  if ( (pos <=0) || (pos > li->qtd))
    return -2; // erro de posição inválida

    if(pos>li->qtd)
      li->dados[pos-1]=al;// aponta para o ponteiro o valor encontrando assim podendo ser lido na main 
    else
    {
        int k,i = 0;
        while(i<li->qtd && li->dados[i].matricula < al.matricula) // procura a pocisção onde vai começar a ordenação
            i++;

        for(k=li->qtd-1; k >= i; k--)
            li->dados[k+1] = li->dados[k];

        li->dados[i] = al;
        li->qtd++;
    }
    
  
  return 0;
}