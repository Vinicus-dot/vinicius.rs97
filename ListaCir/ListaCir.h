#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
typedef struct lista Lista;

struct aluno
{
int matricula;
char nome[30];
float n1,n2,n3;
};
typedef struct aluno Aluno;


Lista* list_create();

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
int run(Lista *li, struct aluno *al);