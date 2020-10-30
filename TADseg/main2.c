#include "tadcre.h"
#include <stdio.h>
#include <time.h>

struct TMat2D
{
  int nrows; // número de linhas
  int ncolumns; // número de colunas
  double *data; // ponteiro para os dados da matriz
};


TMat2D *mat2D_create(int nlin, int ncol)
{
 

  if ( (nlin <= 0 ) || (ncol <=0) ){
    return NULL;
  }

  TMat2D *mat;  
  mat = (TMat2D *)malloc(sizeof(TMat2D));// aloca 12 bytes // FFFFFF // aloca a struct
                                // nlin, ncol, *data
  if (mat == NULL){
    return NULL;
  }

  mat->data = (double *)malloc( sizeof(double) * nlin * ncol ); // aloca a quantidade de valores da struct
  if (mat->data == NULL){
      free(mat);
      return NULL;
  }

  mat->nlin = nlin;
  mat->ncol = ncol;

   
  return mat;

}

void mat2D_free(TMat2D *mat)
{
    free(mat);
}

int mat2D_set_value(TMat2D *mat, int i, int j, double val, int x,int y,double *ma )
{
   
    
   ma[i*y+j]=val;
   
    if( ma[i*y+j]==val)
        return 0;
    else
        return -1;
            
}
int mat2D_get_value(TMat2D *mat, int i, int j, double *val ,int x,int y,double *ma)
{
    
    *val= ma[i*y+j];
    if( *val== ma[i*y+j])
        return 0;
    else
        return -1;
}
int preencher(TMat2D *mat, int i, int j,int x,int y,double *ma)
{
    srand(time(NULL));
    
    int cont=0;
    for(int k=0; k < mat->nrows; k++)
        for(int l=0; l < mat->ncolumns; l++)
        {    
            ma[k*y+l]= (double)((rand() % j) + (i));
            if(ma[k*y+l]<i&&ma[k*y+l]>j)
                cont++;
        }
    if(cont>0)
        return -1;
    else
        return 0;
    
} 
void mostrar(TMat2D *mat,double *ma)
{
    
    for(int k=0; k < mat->nrows; k++)
    {    for(int l=0; l < mat->ncolumns; l++)
        {    
            printf("%.0lf ",ma[k*mat->ncolumns+l]);
        }
    printf("\n");
    }
    printf("\n");
}
void somar(TMat2D *mat, double *me,double *ma,double *rest)
{
    for (int i = 0; i < mat->nrows; i++)
        for (int j = 0; j < mat->ncolumns; j++)
            rest[i*mat->ncolumns+j] = ma[i*mat->ncolumns+j] + me[i*mat->ncolumns+j];
      
}  
void mutiplicar(TMat2D *mat,TMat2D *matt, double *me,double *ma,double *rest)
{
    double matrizz[mat->nrows][mat->ncolumns];
    double matrizz1[matt->nrows][matt->ncolumns];

    for (int i = 0; i < mat->nrows; i++)
    {   for (int j = 0; j < mat->ncolumns; j++)
        {    
            matrizz[i][j] = ma[i*mat->ncolumns+j];
            
        }
       
    }
     for (int i = 0; i < matt->nrows; i++)
    {   for (int j = 0; j < matt->ncolumns; j++)
        {    
            matrizz1[i][j] = me[i*matt->ncolumns+j];
            
        }
       
    }
    for (int i = 0; i < mat->nrows; i++)
    {   
        for (int j = 0; j < matt->ncolumns; j++)
        {
			
			double aux = 0;
			for(int x = 0; x < matt->nrows; x++) {
				aux +=  matrizz[i][x] * matrizz1[x][j];
			}

			rest[i*matt->ncolumns+j] = aux;
			aux = 0;
		}
	}

} 
void mutiplicarES(TMat2D *mat,double *rest,int x)
{
    for (int i = 0; i < mat->nrows; i++)
        for (int j = 0; j < mat->ncolumns; j++)
            rest[i*mat->ncolumns+j]*= x;
      
}  
double traco(TMat2D *mat,double *rest)
{
    double soma=0;
    for (int i = 0; i < mat->nrows; i++)
            soma+=rest[i*mat->ncolumns+i];
    return soma;
} 
double* somaL(TMat2D *mat,double *rest)
{
    double soma=0;
    double *vet; 
    vet = (double *) malloc(sizeof(double) * mat->nrows);
    for (int i = 0; i < mat->nrows; i++)
    {   
        soma=0;
        for (int j = 0; j < mat->ncolumns; j++)
            soma+=rest[i*mat->ncolumns+j];
        vet[i]=soma;
    } 
    return vet;
} 
double* somaC(TMat2D *mat,double *rest)
{
    double soma=0;
    double *vet; 
    vet = (double *) malloc(sizeof(double) * mat->nrows);
    for (int i = 0; i < mat->nrows; i++)
    {   
        soma=0;
        for (int j = 0; j < mat->ncolumns; j++)
            soma+=rest[j*mat->ncolumns+i];
        vet[i]=soma;
    } 
    return vet;
}
TMat *altera_tamanho(int nlin, int ncol)
{
 

  if ( (nlin <= 0 ) || (ncol <=0) ){
    return NULL;
  }

  

  
  mat->data = realloc(li->data , nlin * ncol* sizeof(int));
  if (mat->data == NULL){
      free(mat);
      return NULL;
  }

  mat->nlin = nlin;
  mat->ncol = ncol;

   
  return mat;

}