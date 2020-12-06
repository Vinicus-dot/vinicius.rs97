#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Fila_EST_RC.h"

int main()
{

    struct aluno a, b, c, d, e;

    strcpy(a.nome, "Joao");
    a.matricula = 123;
    a.n1 = a.n2 = a.n3 = 0;

    strcpy(b.nome, "Maria");
    b.matricula = 124;
    b.n1 = b.n2 = b.n3 = 10;

    strcpy(c.nome, "jose");
    c.matricula = 125;
    c.n1 = c.n2 = c.n3 = 10;

    strcpy(d.nome, "godao");
    d.matricula = 120;
    d.n1 = d.n2 = d.n3 = 10;

    strcpy(e.nome, "rudrigo");
    e.matricula = 135;
    e.n1 = e.n2 = e.n3 = 10;

    Dqueue *queue;
    queue = newqueue(2);

    if (queue_push_front(queue, a) != SUCCESS)
    {
        printf("Erro! falta de memória\n");
    }

    if (queue_push_front(queue, b) != SUCCESS)
    {
        printf("Erro! falta de memória\n");
    }

    if (queue_push_front(queue, c) != SUCCESS)
    {
        printf("Erro! falta de memória\n");
    }
    queue_pop_back(queue);
    queue_pop_back(queue);
    queue_pop_back(queue);
    if (queue_push_front(queue, d) != SUCCESS)
    {
        printf("Erro! falta de memória\n");
    }
    queue = compactarL(queue);
    if (queue_push_front(queue, e) != SUCCESS)
    {
        printf("Erro! falta de memória\n");
    }

    queue_print(queue);
}