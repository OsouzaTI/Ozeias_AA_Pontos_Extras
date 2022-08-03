/**
 * @file main.c
 * @author Ozeias Souza
 * @brief Algoritmo para determinar a melhor ordem para multiplicação de
 * matrizes
 * @version 0.1
 * @date 2022-07-05
 * 
 * @copyright Copyright (c) 2022
 */

#include <stdio.h>
#include <stdlib.h>

#define IDX(x) (x-1)

typedef struct matrix { 
    int rows;
    int cols;
    union {int** v;};
} Matrix;

void loadMatrix(Matrix* matrix) {
    matrix->v = (int**)calloc(matrix->rows, sizeof(int));
    for (int i = 0; i < matrix->rows; i++)
        matrix->v[i] = (int*)calloc(matrix->cols, sizeof(int));
}

void showMatrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
            printf("%d\t", matrix->v[i][j]);
        printf("\n");
    }    
}

// TODO: destroy matrix

int main() {

    int nMatrizes = 6;

    // matrizes que serao calculadas
    Matrix m1 = {.rows=30, .cols = 35};
    Matrix m2 = {.rows=35, .cols = 15};
    Matrix m3 = {.rows=15, .cols =  5};
    Matrix m4 = {.rows=5, .cols  = 10};
    Matrix m5 = {.rows=10, .cols = 20};
    Matrix m6 = {.rows=20, .cols = 25};

    // Duvida
    Matrix m7 = {.rows=25, .cols = 25};

    Matrix* matrizes[] = { &m1,&m2,&m3,&m4,&m5,&m6,&m7 };

    // matrizes auxiliares
    Matrix M = {.cols = 7, .rows = 7};
    Matrix S = {.cols = 7, .rows = 7};

    loadMatrix(&M);
    loadMatrix(&S);

    int i = 1, j_aux = 2, j = 2, n_iteracoes = ((nMatrizes * nMatrizes)- nMatrizes)/2;
    for (int it = 0; it < n_iteracoes; it++)
    {
        Matrix *mat_i, *mat_k, *mat_j;
        mat_i = matrizes[i-1];
        int k, m[2], p[3], temp = -1, resultado = -1;
        for(k = i; k < j; k++) {
            mat_k = matrizes[k];
            mat_j = matrizes[j];

            m[0] = M.v[i][k];
            m[1] = M.v[k+1][j];
            p[0] = mat_i->rows;
            p[1] = mat_k->rows;
            p[2] = mat_j->rows;

            if(resultado < 0) {
                resultado = m[0] + m[1] + p[0] * p[1] * p[2];
            } else {
                temp = m[0] + m[1] + p[0] * p[1] * p[2];
                if(temp < resultado)
                    resultado = temp;
            }
        }       
        M.v[i][j] = resultado;
        if(j == nMatrizes) {
            i = 1; j = j_aux + 1;
            j_aux++;     
        } else {
            i++; j++;
        }
    }
    showMatrix(&M);
    

    return 0;
}