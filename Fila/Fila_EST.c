#include <stdio.h>
#include <stdlib.h>
#include "Fila_EST.h"

struct dqueue
{
    int size;
    int MAX;
    int begin;
    int end;

    struct aluno dados[2];
};

Dqueue *newqueue()
{

    Dqueue *li;
    li = malloc(sizeof(struct dqueue)); // Aloca minha lista
    if (li != NULL)
    {
        li->end = li->begin = 0;
        li->size = 0; //quantidade de elementos na lista
        li->MAX = 2;  //guarda o valor max da lista em momento de execução
    }

    if (li->dados == NULL)
    {
        free(li);
        return NULL;
    }

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
        return INVALID_NULL_POINTER;
    if (li->size == li->MAX) //lista cheia
    {
        return OUT_OF_MEMORY;
    }

    li->dados[li->end] = al;
    li->end += 1;
    if (li->end == li->MAX)
    {
        li->end = 0;
    }
    li->size++;
    return SUCCESS;
}
void queue_print(Dqueue *li)
{
    if (li == NULL)
        return;
    for (int i = li->begin; i < li->MAX; i++)
    {
        printf("Matricula: %d\n", li->dados[i].matricula);
        printf("Nome: %s\n", li->dados[i].nome);
        printf("Notas: %.2f, %.2f, %.2f\n", li->dados[i].n1, li->dados[i].n2, li->dados[i].n3);
        printf("-------------------------------\n");
    }
    return;
}
int queue_pop_back(Dqueue *li)
{

    if (li == NULL)
        return INVALID_NULL_POINTER;
    if (li->size == 0)
        return OUT_OF_MEMORY;

    
    li->begin += 1;
    if (li->begin == li->MAX)
    {
        li->begin = 0;
    }

    li->size--; //remove do final da lista um valor
    return SUCCESS;
}