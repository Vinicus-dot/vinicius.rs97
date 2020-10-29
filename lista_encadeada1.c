#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

typedef struct No No;

//Definição do tipo lista
typedef struct lista
{
  No *inicio;

} Lista;
//Definição do nó da lista
struct No
{
  No *prox;
  struct aluno dado;
};

Lista *cria_lista()
{
  Lista *li;

  li = (Lista *)malloc(sizeof(struct lista)); // poderia ser Lista

  if (li == NULL)
  {
    return NULL;
  }

  li->inicio = NULL;

  return li;
}

int list_push_front(Lista *li, struct aluno al)
{
  if (li == NULL)
  {
    return 0;
  }

  No *novo_no = (No *)malloc(sizeof(struct No));

  if (novo_no == NULL)
  {
    return 0;
  }

  novo_no->dado = al;

  novo_no->prox = li->inicio;
  li->inicio = novo_no;

  return 1;
}
int list_push_pos(Lista *li, int pos, struct aluno al)
{

  if (li == NULL)
    return -1;

  if (li->inicio->prox == NULL || pos == 1)
  {
    list_push_front(li, al);
    return 0;
  }
  int cont = 1;
  No *aux = li->inicio;
  No *novo_no = (No *)malloc(sizeof(struct No));
  novo_no->dado = al;

  
  while (aux != NULL)
  {
    if (pos - 1 == cont)
    {

      novo_no->prox = aux->prox;
      aux->prox = novo_no;

      return 0;
    }

    cont++;
    aux = aux->prox;
  }

  return -2;
}
int list_insert_sorted(Lista *li, struct aluno al)
{
  if (li == NULL)
    return -1;

  No *aux = li->inicio;

  No *novo_no = (No *)malloc(sizeof(struct No));
  novo_no->dado = al;
  if (li->inicio == NULL)
  {
    novo_no->prox = li->inicio;
    li->inicio = novo_no;

    return 0;
  }
  while (aux != NULL)
  {

    if (al.matricula > aux->dado.matricula)
    {

      novo_no->prox = aux->prox;
      aux->prox = novo_no;
      return 0;
    }
    aux = aux->prox;
  }

  return 0;
}

int list_push_back(Lista *li, struct aluno al)
{
  if (li == NULL)
  {
    return 0;
  }

  No *novo_no = (No *)malloc(sizeof(struct No));

  if (novo_no == NULL)
  {
    return 0;
  }

  novo_no->dado = al;
  novo_no->prox = NULL;

  if (li->inicio == NULL)
  {
    li->inicio = novo_no;
    return 1;
  }

  No *aux = li->inicio;
  while (aux->prox != NULL)
  {
    aux = aux->prox;
  }

  aux->prox = novo_no;

  return 1;
}

int list_remove_front(Lista *li)
{
  if (li == NULL)
  {
    return 0;
  }

  if (li->inicio == NULL)
  {
    return 0;
  }

  No *aux = li->inicio;

  li->inicio = aux->prox;

  free(aux);

  return 1;
}

int list_remove_back(Lista *li)
{
  if (li == NULL)
  {
    return 0;
  }

  if (li->inicio == NULL)
  {
    return 0;
  }

  if (li->inicio->prox == NULL)
  {
    free(li->inicio);
    li->inicio = NULL;
    return 1;
  }

  No *ant = NULL;
  No *aux = li->inicio;

  while (aux->prox != NULL)
  {
    ant = aux;
    aux = aux->prox;
  }

  ant->prox = NULL;
  free(aux);

  return 1;
}

void list_free(Lista *li)
{
  if (li == NULL)
  {
    return;
  }

  No *aux = li->inicio;
  No *b = NULL;
  while (aux != NULL)
  {
    b = aux;
    aux = aux->prox;
    free(b);
  }

  free(li);
}

void list_print(Lista *li)
{
  if (li == NULL)
  {
    return;
  }

  No *aux = li->inicio;
  printf("\n\nLista: \n");
  while (aux != NULL)
  {
    printf("Matricula: %d\n", aux->dado.matricula);
    printf("Nome: %s\n", aux->dado.nome);
    printf("Notas: %.2f, %.2f, %.2f\n", aux->dado.n1, aux->dado.n2, aux->dado.n3);
    printf("-------------------------------\n");
    aux = aux->prox;
  }
  return;
}

int list_get_pos(Lista *li, int pos, struct aluno *al)
{

  if (li == NULL)
    return -1;

  int cont = 1;
  No *aux = li->inicio;
  while (aux != NULL)
  {
    if (pos == cont)
    {
      *al = aux->dado;
      return 0;
    }
    cont++;
    aux = aux->prox;
  }

  return -3;
}
int list_get_mat(Lista *li, int mat, struct aluno *al)
{
  if (li == NULL)
    return -1;

  No *aux = li->inicio;
  while (aux != NULL)
  {
    if (mat == aux->dado.matricula)
    {
      *al = aux->dado;
      return 0;
    }

    aux = aux->prox;
  }

  return -2;
}
int list_size(Lista *li)
{
  if (li == NULL)
    return -1;
  int cont = 0;
  No *aux = li->inicio;
  while (aux != NULL)
  {
    cont++;
    aux = aux->prox;
  }
  return cont;
}
int list_empty(Lista *li)
{
  if (li->inicio == NULL)
    return 0;
  else
    return -4;
}
int list_full(Lista *li)
{

  return 0;
}
