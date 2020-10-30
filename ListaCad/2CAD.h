#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct List2 List2;


List2* list_create();
int list_free(List2 *li);

int list_push_front(List2 *li, struct aluno al);
int list_push_back(List2 *li, struct aluno al);
int list_insert(List2* li, int pos, struct aluno al);
int list_size(List2 *li);

int list_pop_front(List2 *li);
int list_pop_back(List2 *li);


int list_erase(List2 *li, int pos);

int list_find_pos(List2 *li, int pos, struct aluno *al); 
int list_find_mat(List2 *li, int nmat, struct aluno *al);
int list_front(List2 *li, struct aluno *al); 
int list_back(List2 *li, struct aluno *al); 
int list_get_pos(List2 *li, int nmat, int *pos);

int list_print_forward(List2 *li);
int list_print_reverse(List2 *li);