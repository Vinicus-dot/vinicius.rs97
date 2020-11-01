#include "STSEG.h"
#include <stdlib.h>
#include <stdio.h>




struct stack {
    int qtd;
    int MAX;
    struct aluno *dados;
};

stack *stack_create(int n){
     
    stack *li;
    li = malloc(sizeof(struct stack));// Aloca minha lista 
    if(li != NULL)
    {    
        li->qtd = 0;//quantidade de elementos na lista
        li->MAX = n;//guarda o valor max da lista em momento de execução
    }
    
    li->dados = (Aluno*) malloc(sizeof( Aluno )*n);// aloca a quantidade de alunos vao ser inseridos 
    if (li->dados == NULL){
      stack_free(li);
      return NULL;
    }
    
    
    return li;
}

int stack_push(stack *st, struct aluno al){
    if (st == NULL){
       return INVALID_NULL_POINTER; 
    } else
    {
     if(st->qtd == st->MAX)//lista cheia
        {   
           return OUT_OF_MEMORY;
        }
 
    for(int i=st->qtd-1; i>=0; i--)
        st->dados[i+1] = st->dados[i];// movendo todos os dados de alunos para frente para poder ocupar o local 1 o novo al

    st->dados[0] = al;
    st->qtd++;
 
    return 0;
       
    }
}

int stack_print(stack* li)
{
    if (li == NULL)
        return -1;
    for (int i =0; i < li->qtd; i++)  
    {
        printf("%c\n",li->dados->nome);
        
    }
  return 0;

   
}
int stack_empty(stack *st)
{
    if(st == NULL)
        return INVALID_NULL_POINTER;
    if(st->qtd == SUCCESS)
        return SUCCESS;
    return OUT_OF_MEMORY;
    
}
int stack_size(stack *st)
{
    if (st == NULL){
       return INVALID_NULL_POINTER; 
    }else
        return st->qtd;

}
int stack_pop(stack *li)
{
     if (li == NULL){
       return INVALID_NULL_POINTER; 
    } 
    if(li->qtd == 0)
        return OUT_OF_MEMORY;

    int k = 0;
    for(k=0; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];// aqui move todos os numero sem ser o primeiro 1 casa a tras para poder remover do inicio
 
    li->qtd--;
    return SUCCESS;
    
}
void stack_free(stack *st)
{
    free(st);//libera o espaço ocupado pela memoria
}