#ifndef STSEGh
#define STSEGh
typedef struct stack stack;

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2


struct aluno
{
    char nome;

};
typedef struct aluno Aluno;

stack*  stack_create();


void stack_free(stack *st);

int stack_push(stack *st, struct aluno al);

int stack_pop(stack *st);


int stack_empty(stack *st);
int stack_size(stack *st);

int stack_print(stack* st);

#endif