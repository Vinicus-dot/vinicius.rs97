#include <stdio.h>
#include <stdlib.h>
#include "ListaCir.h"

typedef struct No No;

//Definição do tipo lista
typedef struct lista
{
    No *save;
    No *begin;
    No *end;
    int size;

} Lista;
//Definição do nó da lista
struct No
{
    No *next;
    struct aluno dado;
};

Lista *list_create()
{
    Lista *li;

    li = (Lista *)malloc(sizeof(struct lista)); // poderia ser Lista

    if (li == NULL)
    {
        return NULL;
    }
    li->size = 0;
    li->end = NULL;
    li->begin = NULL;
    li->save = NULL;

    return li;
}

int list_push_front(Lista *li, struct aluno al)
{
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    No *novo_no = (No *)malloc(sizeof(struct No));

    if (novo_no == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    if (li->begin == NULL)
    {
        novo_no->dado = al;

        novo_no->next = li->begin;
        li->begin = li->end = novo_no;
        li->end->next = li->begin;
    }
    else
    {
        novo_no->dado = al;

        novo_no->next = li->begin;
        li->begin = novo_no;
    }
    li->size++;
    return SUCCESS;
}
int list_push_pos(Lista *li, int pos, struct aluno al)
{

    if (li == NULL)
        return INVALID_NULL_POINTER;

    if (li->begin == NULL || pos == 1)
    {
        list_push_front(li, al);
        return SUCCESS;
    }
    if (pos >= li->size)
    {
        list_push_back(li, al);
        return SUCCESS;
    }
    int cont = 1;
    No *aux = li->begin;
    No *novo_no = (No *)malloc(sizeof(struct No));
    novo_no->dado = al;

    while (aux != NULL)
    {
        if (pos - 1 == cont)
        {

            novo_no->next = aux->next;
            aux->next = novo_no;
            li->size++;
            return SUCCESS;
        }

        cont++;
        aux = aux->next;
    }

    return OUT_OF_MEMORY;
}
int list_insert_sorted(Lista *li, struct aluno al)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    if (li->begin == NULL)
    {
        list_push_front(li, al);
        return SUCCESS;
    }
    else
    {

        No *aux = li->begin;

        No *novo_no = (No *)malloc(sizeof(struct No));
        novo_no->dado = al;

        while (aux != NULL)
        {

            if (al.matricula > aux->dado.matricula)
            {

                novo_no->next = aux->next;
                aux->next = novo_no;
                li->size++;
                return SUCCESS;
            }
            aux = aux->next;
        }
    }
    return ELEM_NOT_FOUND;
}
int list_push_back(Lista *li, struct aluno al)
{
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    No *novo_no = (No *)malloc(sizeof(struct No));

    if (novo_no == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    novo_no->dado = al;
    novo_no->next = li->begin;

    if (li->begin == NULL)
        li->begin = li->end = novo_no;
    else
    {
        li->end->next = novo_no;
        li->end = novo_no;
    }
    li->size++;
    return SUCCESS;
}
int list_remove_front(Lista *li)
{
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    if (li->begin == NULL)
    {
        return OUT_OF_MEMORY;
    }

    No *aux = li->begin;

    li->begin = aux->next;
    li->end->next = li->begin;
    li->size--;

    free(aux);

    return SUCCESS;
}

int list_remove_back(Lista *li)
{
    if (li == NULL)
    {
        return INVALID_NULL_POINTER;
    }

    if (li->begin == NULL)
    {
        return OUT_OF_MEMORY;
    }

    if (li->size == 1)
    {
        free(li->begin);
        li->begin = NULL;
    }
    else
    {
        int cont = 1;
        No *aux = li->begin;
        while (aux != li->end)
        {
            if (li->size - 1 == cont)
            {
                free(aux->next);
                li->end = aux;
                aux->next = li->begin;
            }
            cont++;
            aux = aux->next;
        }
    }

    li->size--;
    return SUCCESS;
}

void list_free(Lista *li)
{
    if (li == NULL)
    {
        return;
    }

    No *aux = li->begin;
    No *b = NULL;
    while (aux != li->end)
    {
        b = aux;
        aux = aux->next;
        free(b);
    }
    free(li->end);

    free(li);
}

void list_print(Lista *li)
{
    if (li == NULL)
    {
        return;
    }
    int cont = 0;
    No *aux = li->begin;
    printf("\n\nLista: \n");
    while (cont != li->size)
    {
        printf("Matricula: %d\n", aux->dado.matricula);
        printf("Nome: %s\n", aux->dado.nome);
        printf("Notas: %.2f, %.2f, %.2f\n", aux->dado.n1, aux->dado.n2, aux->dado.n3);
        printf("-------------------------------\n");
        aux = aux->next;
        cont++;
    }
    return;
}

int list_get_pos(Lista *li, int pos, struct aluno *al)
{

    if (li == NULL)
        return INVALID_NULL_POINTER;

    int cont = 1;
    No *aux = li->begin;
    while (aux != li->end)
    {
        if (pos == cont)
        {
            *al = aux->dado;
            return SUCCESS;
        }
        cont++;
        aux = aux->next;
    }

    return OUT_OF_RANGE;
}
int list_get_mat(Lista *li, int mat, struct aluno *al)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    No *aux = li->begin;
    while (aux != li->end)
    {
        if (mat == aux->dado.matricula)
        {
            *al = aux->dado;
            return SUCCESS;
        }

        aux = aux->next;
    }

    return OUT_OF_MEMORY;
}
int list_size(Lista *li)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    return li->size;
}
int list_empty(Lista *li)
{
    if (li->begin == NULL)
        return SUCCESS;
    else
        return ELEM_NOT_FOUND;
}
int list_full(Lista *li)
{

    return 0;
}
int run(Lista *li, struct aluno *al)// função que retornará sempre o próximo elemento. Por exemplo, se a lista não foi percorrida ainda, o próximo elemento é a cabeça. Depois, ao chamar a função novamente, será devolvido o segundo elemento, e assim sucessivamente.
{
    if (li == NULL)
        return INVALID_NULL_POINTER;
    else if (li->begin == NULL)
        return INVALID_NULL_POINTER;

    if (li->save == NULL)
        li->save = li->begin;
    else
        li->save = li->save->next;

    *al = li->save->dado;
    return SUCCESS;
}
