#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Fila_ECD.h"
int main()
{

    Dqueue *queue;
    queue = newqueue();

    struct aluno a;
    a.n1 = a.n2 = a.n3 = 0;
    a.matricula = 16;
    strcpy(a.nome, "HENRI");
    int ret = queue_push_front(queue, a);
    if (ret != 0)
    {
        printf("ERRO!");
    }
    
    a.matricula = 11;
    strcpy(a.nome, "HENRIQUEZERA");
    ret = queue_push_front(queue, a);
    if (ret != 0)
    {
        printf("ERRO!");
    }
    queue_print(queue);
    queue_pop_back(queue);
    last_of_queue(queue);
}