#include <stdio.h>
#include "tadcre.h"
struct TMat2D
{
  int nrows; // número de linhas
  int ncolumns; // número de colunas
  double *data; // ponteiro para os dados da matriz
};


int main(void) {
  

  TMat2D *matriz;

  matriz = mat2D_create(3,3);
  
  double ma[matriz->nrows][matriz->ncolumns],me[matriz->nrows][matriz->ncolumns],rest[matriz->nrows][matriz->ncolumns];
  
  printf("Set 20 na posicao 0 0:\n");
  
  int ret = mat2D_set_value(matriz, 0, 0, 20,matriz->nrows,matriz->ncolumns,(double *)ma);
  if (ret == -1){

  printf("ERROO!!");
  }
  mostrar(matriz,(double *)ma);
  printf("Get na posicao 0 0\n");
  double val=3.3;
  int get = mat2D_get_value(matriz, 0, 0, &val,matriz->nrows,matriz->ncolumns,(double *)ma);
  if (get == -1){

  printf("ERROO!!");
  }
  else
  {
    printf("Numero nessa poicao eh: %.1lf\n",val);
  }
  
  int xet =preencher(matriz, 1, 2,matriz->nrows,matriz->ncolumns,(double *)ma);
  if (xet == -1){

  printf("ERROO!!");
  }
  int ket =preencher(matriz, 1,4 ,matriz->nrows,matriz->ncolumns,(double *)me);
  if (ket == -1){

  printf("ERROO!!");
  }
  printf("Os numeros da matriz foram preenchidos aleatoriamente:\n\n");
  printf("Matriz 1\n");
    mostrar(matriz,(double *)ma);
  printf("Matriz 2\n");
  mostrar(matriz,(double *)me);
  somar(matriz, (double *)me,(double *)ma,(double *)rest);
  printf("Soma das 2 matriz:\n");
  mostrar(matriz,(double *)rest);
  printf("Mutiplicacao das 2 matriz:\n");
  mutiplicar(matriz, matriz,(double *)me,(double *)ma,(double *)rest);
 mostrar(matriz,(double *)rest);
  printf("Mutiplicacao da matriz anterior por 3 :\n");
 mutiplicarES(matriz,(double *)rest, 3);
 mostrar(matriz,(double *)rest);

 printf("Traco da matriz anterior: %.2lf\n",traco(matriz, (double *)rest));
 double *vet;
 vet=somaL(matriz,(double *)rest);
 printf("Soma linha:\n");
 for(int i=0 ; i<matriz->nrows; i++)
  printf("%.0lf ",vet[i]);
 printf("\nSoma Coluna:\n");
vet=somaC(matriz,(double *)rest);
 for(int i=0 ; i<matriz->nrows; i++)
  printf("%.0lf ",vet[i]);
mat2D_free(matriz);
  return 0;
}