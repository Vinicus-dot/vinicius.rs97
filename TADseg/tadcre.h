#include <stdlib.h>



typedef struct TMat2D TMat2D; 


TMat2D *mat2D_create(int nrows, int ncolumns);

void mat2D_free(TMat2D *mat);

int mat2D_set_value(TMat2D *mat, int i, int j, double val, int x,int y,double *ma );
int mat2D_get_value(TMat2D *mat, int i, int j, double *val ,int x,int y,double *ma);
int preencher(TMat2D *mat, int i, int j,int x,int y,double *ma);
void mostrar(TMat2D *mat,double *ma);
void somar(TMat2D *mat, double *me , double *ma, double *rest);
void mutiplicar(TMat2D *mat,TMat2D *matt, double *me,double *ma,double *rest);
void mutiplicarES(TMat2D *mat,double *rest,int x);
double traco(TMat2D *mat,double *rest);
double* somaL(TMat2D *mat,double *rest);
double* somaC(TMat2D *mat,double *rest);