#include <stdio.h>
#include "2CAD.h"
#include <string.h>

int main(void)
{
  printf("Hello World\n");

  struct aluno a;

  strcpy(a.nome, "Joao");
  a.matricula = 123;
  a.n1 = a.n2 = a.n3 = 0;

  List2 *lista;
  lista = list_create();
  if (lista == NULL)
  {
    printf("ERRO: memória insuficiente");
  }
  else
  {
    list_push_back(lista, a);
  }
  a.matricula = 16;
  strcpy(a.nome, "HENRI");
  int ret = list_push_front(lista, a);
  if (ret == -4)
  {
    printf("ERRO!");
  }
  a.matricula = 15;
  strcpy(a.nome, "HENRIaaaaa");
  ret = list_insert(lista, 2, a);
  if (ret == -4)
  {
    printf("ERRO!");
  }
  list_print_forward(lista);
  list_erase(lista, 2);
  list_print_reverse(lista);

  struct aluno b;
  if (list_find_pos(lista, 1, &b) == 0)
  {
    printf("\n%s\n", b.nome);
  }
  else
  {
    printf("erro!");
  }
  if (list_find_mat(lista, 16, &b) == 0)
  {
    printf("\n%s\n", b.nome);
  }
  if (list_back(lista, &b) == 0)
  {
    printf("\n%s\n", b.nome);
  }
  printf("Quantidade na lista n:%d", list_size(lista));
  int z;
   if (list_get_pos(lista, 16, &z) == 0)
  {
    printf("\nSize:%d\n", z);
  }

  return 0;
}