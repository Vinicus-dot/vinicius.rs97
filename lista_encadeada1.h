typedef struct lista Lista;

#ifndef lista_encadeada1.h
#define lista_encadeada1.h

#include "aluno.h"



Lista* cria_lista();
int list_push_front(Lista* li, struct aluno al);
int list_push_back(Lista* li, struct aluno al);
int list_remove_front(Lista* li);
int list_remove_back(Lista* li);
void list_print(Lista* li);
void list_free(Lista* li);
int list_get_pos(Lista* li, int pos, struct aluno *al);
int list_get_mat(Lista* li, int mat, struct aluno *al);
int list_insert_sorted(Lista* li, struct aluno al);
int list_size(Lista* li);
int list_full(Lista* li);
int list_empty(Lista* li);
int list_push_pos(Lista* li, int pos, struct aluno al);

#endif
