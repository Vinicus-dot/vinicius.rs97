#include "ST.h"
#include <stdlib.h>
#include "..\ListaCad\lista_encadeada1.h"

struct stack {

    Lista *data;
};

stack *stack_create(){
    stack *st;
    st = malloc(sizeof(struct stack));
    if (st != NULL){
        st->data  = cria_lista();
        if (st->data == NULL){
            free(st);
            st = NULL;
        }
    }
    return st;
}

int stack_push(stack *st, struct aluno al){
    if (st == NULL){
       return INVALID_NULL_POINTER; 
    } else
    {
        return list_push_front(st->data,al);
       
    }
}

void stack_print(stack* st)
{
    
    list_print(st->data);
}

int stack_empty(stack *st)
{
    return list_empty(st->data);
    
}
int stack_size(stack *st)
{
    if (st == NULL){
       return INVALID_NULL_POINTER; 
    } else
    {
        return list_size(st->data);
       
    }

}
int stack_pop(stack *st)
{
     if (st == NULL){
       return INVALID_NULL_POINTER; 
    } else
    {
        return list_remove_front(st->data);
       
    }
    
}