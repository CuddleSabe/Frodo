#ifndef __FRODO_H__
#define __FRODO_H__ 

#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
/*//////////////////////////// 
// Author: Latty7, CuddleSabe/ 
*///////////////////////////// 
typedef struct matrix
{
	int row,cow;
	double **matrix;
}Matrix;

Matrix* MatrixMultiply(Matrix *a, Matrix *b)	//矩阵乘法 
{
	int i,j,k;
	Matrix *newMatrix;
	newMatrix = (Matrix*)malloc(sizeof(Matrix));
	
	newMatrix->matrix = (double**)malloc(sizeof(double*)*(a->row));
	for(i=0;i<a->row;i++)
		newMatrix->matrix[i]= (double*)malloc(sizeof(double*)*(b->cow));
	newMatrix->cow=b->cow;
	newMatrix->row=a->row;
	

	for(i=0;i<a->row;i++)
			for(j=0;j<b->cow;j++)
				for(k=0;k<a->cow;k++) {
					newMatrix->matrix[i][j]+=(a->matrix[i][k])*(b->matrix[k][j]);
				}
	return newMatrix;
}

void InitMatrix(Matrix *a)	//初始化矩阵 
{
	int i,j;
	scanf("%d",&(a->row));
	scanf("%d",&(a->cow));
	a->matrix = (double**)malloc(sizeof(double*)*(a->row));
	for(i=0;i<a->row;i++)
		a->matrix[i]= (double*)malloc(sizeof(double*)*(a->cow));
	for(i=0; i<a->row;i++)
		for(j=0; j<a->cow;j++)
			scanf("%lf",&(a->matrix[i][j]));
}
	
Matrix* MatrixPlus(Matrix *a, Matrix *b)	//矩阵加法 
{
	if((a->cow!=b->cow)||((a->row!=b->row)))
		{
			printf("Matrix does not match!\nerror:101");
			exit(0);
		}	
	int i,j;
	Matrix *newMatrix;
	newMatrix = (Matrix*)malloc(sizeof(Matrix));
	newMatrix->matrix = (double**)malloc(sizeof(double*)*(a->row));
	for(i=0;i<a->row;i++)
		newMatrix->matrix[i]= (double*)malloc(sizeof(double*)*(b->cow));
	newMatrix->cow=b->cow;
	newMatrix->row=a->row;
	for(i=0; i<a->row;i++)
		for(j=0; j<a->cow;j++)
			newMatrix->matrix[i][j]=a->matrix[i][j] + b->matrix[i][j];
	return newMatrix;
}
	
void ShowMatrix(Matrix *a)	//矩阵展示 
{	
	int i,j;
	for(i=0;i<a->row;i++)
	{
		for(j=0;j<a->cow;j++)
			printf("%lf ",a->matrix[i][j]);
		printf("\n");
	}
}

#endif

