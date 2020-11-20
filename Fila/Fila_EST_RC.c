#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Fila_EST_RC.h"

struct dqueue
{
    int size;
    int MAX;
    int begin;
    int end;
    int start;

    struct aluno *dados;
};

Dqueue *newqueue(int n)
{

    Dqueue *li;
    li = malloc(sizeof(struct dqueue)); // Aloca minha lista
    if (li != NULL)
    {
        li->end = li->begin = 0;
        li->size = 1; //quantidade de elementos na lista
        li->MAX = n;  //guarda o valor max da lista em momento de execução
        li->start = n;
    }

    li->dados = (Aluno *)malloc(sizeof(Aluno) * n); // aloca a quantidade de alunos vao ser inseridos
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

        li->dados = (Aluno *)realloc(li->dados, li->start * sizeof(Aluno)); // relocando memoria para poder suprir o  usuario
        li->MAX += li->start;
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
    for (int i = 0; i < li->size; i++)
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
Dqueue *compactarL(Dqueue *li)
{
    int x = -2, valor = li->size;

    while (valor != 0)
    {
        x += 1;
        valor = valor / 10; // calculo para padronizar qualquer valor de 2 para cima
    }
    if (x < 0)
        x = 0;

    x = ceil(li->size / pow(10, x)) * pow(10, x);

    li->dados = (Aluno *)realloc(li->dados, x * sizeof(Aluno)); // relocando memoria para poder suprir o  usuario
    li->MAX = x;

    return li;
}