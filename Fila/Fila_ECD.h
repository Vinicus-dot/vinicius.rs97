#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

typedef struct dqueue Dqueue;

struct aluno
{
int matricula;
char nome[30];
float n1,n2,n3;
};
typedef struct aluno Aluno;


Dqueue* newqueue();
int queue_size(Dqueue* li);
int queue_push_front(Dqueue* li, struct aluno al);
int queue_pop_back(Dqueue* li);
void queue_print(Dqueue* li);
void last_of_queue(Dqueue *li);