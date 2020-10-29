#include "2CAD.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct No No;

struct List2
{
  No *begin;
  No *end;
  int size;
};

struct No
{
  struct aluno data;
  No *next;
  No *prev;
};

List2 *list_create()
{
  List2 *list;
  list = malloc(sizeof(List2));
  if (list != NULL)
  {
    list->begin = NULL;
    list->end = NULL;
    list->size = 0;
  }
  return list;
}
int list_free(List2 *li)
{
  if (li == NULL)
  {
    return INVALID_NULL_POINTER;
  }

  No *aux = li->begin;
  No *b = NULL;
  while (aux != NULL)
  {
    b = aux;
    aux = aux->next;
    free(b);
  }
  li->size = 0;
  free(li);

  return SUCCESS;
}

int list_push_front(List2 *li, struct aluno al)
{
  if (li == NULL)
  {
    return INVALID_NULL_POINTER;
  }
  else
  {
    No *node;
    node = malloc(sizeof(No));
    if (node == NULL)
    {
      return OUT_OF_MEMORY;
    }
    else
    {
      node->data = al;
      node->prev = NULL;
      node->next = li->begin;
    }
    // testando se a lista está vazia
    if (li->begin == NULL)
    {
      li->begin = node;
      li->end = node;
      li->size = 1;
    }
    else
    {
      li->begin->prev = node;
      li->begin = node;
      li->size = li->size + 1;
    }
    return SUCCESS;
  }
}

int list_push_back(List2 *li, struct aluno al)
{
  if (li == NULL)
  {
    return INVALID_NULL_POINTER;
  }
  else
  {

    No *novo_no = (No *)malloc(sizeof(struct No));
    if (novo_no == NULL)
    {
      return 0;
    }
    novo_no->data = al;
    novo_no->next = NULL;

    // testando se a lista está vazia
    if (li->begin == NULL)
    {
      li->begin = novo_no;
      li->end = novo_no;
      li->size = 1;
    }
    else
    {
      li->end->next = novo_no;
      novo_no->prev = li->end;
      li->end = novo_no;
      li->size += 1;
    }

    return SUCCESS;
  }
}
int list_insert(List2 *li, int pos, struct aluno al)
{

  if (li == NULL)
    return INVALID_NULL_POINTER;

  if ((pos <= 0) || (pos > li->size + 1))
    return INVALID_NULL_POINTER;

  if (li->begin->next == NULL || pos == 1)
  {
    list_push_front(li, al);
    return SUCCESS;
  }
  else if (li->size == pos || li->size + 1 == pos)
  {
    list_push_back(li, al);
    return SUCCESS;
  }

  int cont = 1;
  No *aux = li->begin;
  No *novo_no = (No *)malloc(sizeof(struct No));
  novo_no->data = al;

  while (aux != NULL)
  {
    if (pos == cont)
    {

      novo_no->next = aux->next;
      aux->next = novo_no;
      aux->next->prev = novo_no;
      novo_no->prev = aux;
      li->size += 1;

      return SUCCESS;
    }

    cont++;
    aux = aux->next;
  }

  return ELEM_NOT_FOUND;
}
int list_size(List2 *li)
{
  if (li == NULL)
    return INVALID_NULL_POINTER;
  int cont = 0;
  No *aux = li->begin;
  while (aux != NULL)
  {
    cont++;
    aux = aux->next;
  }
  return cont;
}
int list_pop_front(List2 *li)
{
  if (li == NULL)
  {
    return INVALID_NULL_POINTER;
  }

  if (li->begin == NULL)
  {
    return ELEM_NOT_FOUND;
  }

  No *aux = li->begin;

  li->begin = aux->next;
  li->begin->prev = NULL;
  li->size -= 1;
  free(aux);

  return SUCCESS;
}
int list_pop_back(List2 *li)
{
  if (li == NULL)
  {
    return INVALID_NULL_POINTER;
  }

  if (li->begin == NULL)
  {
    return ELEM_NOT_FOUND;
  }
  //um elemento na lista
  if (li->begin->next == NULL)
  {

    free(li->end);
    li->begin = NULL;
    li->end = NULL;
    li->size = 0;
    return SUCCESS;
  }

  No *aux = li->end;

  li->end = li->end->prev;
  li->end->next = NULL;

  li->size -= 1;
  free(aux);

  return SUCCESS;
}
int list_erase(List2 *li, int pos)
{
  if (li == NULL)
    return INVALID_NULL_POINTER;

  int cont = 1;
  No *aux = li->begin;
  No *aux2;
  while (aux != NULL)
  {
    if (pos == cont)
    {
      aux2 = aux;
      aux->prev->next = aux2->next;
      aux->next->prev = aux2->prev;
      free(aux2);
      li->size -= 1;
      return SUCCESS;
    }
    cont++;
    aux = aux->next;
  }

  return ELEM_NOT_FOUND;
}
int list_find_pos(List2 *li, int pos, struct aluno *al)
{
  if (li == NULL)
    return INVALID_NULL_POINTER;

  int cont = 1;
  No *aux = li->begin;
  while (aux != NULL)
  {
    if (pos == cont)
    {
      *al = aux->data;
      return SUCCESS;
    }
    cont++;
    aux = aux->next;
  }

  return -3;
}
int list_find_mat(List2 *li, int mat, struct aluno *al)
{
  if (li == NULL)
    return INVALID_NULL_POINTER;

  No *aux = li->begin;
  while (aux != NULL)
  {
    if (mat == aux->data.matricula)
    {
      *al = aux->data;
      return SUCCESS;
    }

    aux = aux->next;
  }

  return OUT_OF_RANGE;
}
int list_front(List2 *li, struct aluno *al)
{
  if (li == NULL)
    return INVALID_NULL_POINTER;
  *al = li->begin->data;
  return SUCCESS;
}
int list_back(List2 *li, struct aluno *al)
{
  if (li == NULL)
    return INVALID_NULL_POINTER;
  *al = li->end->data;
  return SUCCESS;
}
int list_get_pos(List2 *li, int mat, int *pos)
{
  if (li == NULL)
    return INVALID_NULL_POINTER;

  int cont = 1;
  No *aux = li->begin;
  while (aux != NULL)
  {
    if (mat == aux->data.matricula)
    {
      *pos = cont;
      return SUCCESS;
    }
    cont++;
    aux = aux->next;
  }

  return OUT_OF_RANGE;
}

int list_print_forward(List2 *li)
{
  if (li == NULL)
  {
    return INVALID_NULL_POINTER;
  }
  if (li->size == 0)
  {
    return ELEM_NOT_FOUND;
  }

  No *aux = li->begin;

  printf("\n\nLista: \n");
  while (aux != NULL)
  {
    printf("Matricula: %d\n", aux->data.matricula);
    printf("Nome: %s\n", aux->data.nome);
    printf("Notas: %.2f, %.2f, %.2f\n", aux->data.n1, aux->data.n2, aux->data.n3);
    printf("-------------------------------\n");
    aux = aux->next;
  }
  return SUCCESS;
}
int list_print_reverse(List2 *li)
{
  if (li == NULL)
  {
    return INVALID_NULL_POINTER;
  }
  if (li->size == 0)
  {
    return ELEM_NOT_FOUND;
  }

  No *aux = li->end;

  printf("\n\nLista: \n");
  while (aux != NULL)
  {
    printf("Matricula: %d\n", aux->data.matricula);
    printf("Nome: %s\n", aux->data.nome);
    printf("Notas: %.2f, %.2f, %.2f\n", aux->data.n1, aux->data.n2, aux->data.n3);
    printf("-------------------------------\n");
    aux = aux->prev;
  }
  return SUCCESS;
}