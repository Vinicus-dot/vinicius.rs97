#include <stdio.h>
#include <stdlib.h>
#include "Fila_ECD.h"

typedef struct No No;

//Definição do tipo lista
typedef struct dqueue
{
    No *begin;
    No *end;
    int size;

} dqueue;
//Definição do nó da lista
struct No
{
    No *prox;
    struct aluno dado;
};

Dqueue *newqueue()
{
    Dqueue *li;

    li = (Dqueue *)malloc(sizeof(struct dqueue)); // poderia ser Dqueue

    if (li == NULL)
    {
        return NULL;
    }
    li->size = 0;
    li->begin = NULL;
    li->end = NULL;

    return li;
}
int queue_size(Dqueue *li)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;
    else
        return li->size;
}
int queue_push_front(Dqueue *li, struct aluno al)
{
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    No *novo_no = (No *)malloc(sizeof(struct No));

    if (novo_no == NULL)
    {
        return OUT_OF_MEMORY;
    }
    novo_no->dado = al;
    if (li->size == 0)
    {
        novo_no->prox = li->begin;
        li->begin = novo_no;
        li->size += 1;
        li->end = novo_no;
    }
    else
    {
        novo_no->prox = li->begin;
        li->begin = novo_no;
        li->size += 1;
    }

    return SUCCESS;
}
void queue_print(Dqueue *li)
{
    if (li == NULL)
    {
        return;
    }

    No *aux = li->begin;
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
void last_of_queue(Dqueue *li)
{
    if (li == NULL)
    {
        return;
    }

    No *aux = li->end;
    printf("\n\nO Ultimo da Lista: \n");

    printf("Matricula: %d\n", aux->dado.matricula);
    printf("Nome: %s\n", aux->dado.nome);
    printf("Notas: %.2f, %.2f, %.2f\n", aux->dado.n1, aux->dado.n2, aux->dado.n3);
    printf("-------------------------------\n");

    return;
}
int queue_pop_back(Dqueue *li)
{
    if (li == NULL || li->begin == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    if (li->begin->prox == NULL)
    {
        free(li->begin);
        li->begin = NULL;
        return SUCCESS;
    }

    No *ant = NULL;
    No *aux = li->begin;

    while (aux->prox != NULL)
    {
        ant = aux;
        aux = aux->prox;
    }

    ant->prox = NULL;
    li->end = ant;
    free(aux);
    li->size--;
    return SUCCESS;
}