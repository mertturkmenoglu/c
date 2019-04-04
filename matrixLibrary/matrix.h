#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    float **matrix;
    int row;
    int col;
} Matrix;

Matrix *createMatrix(int row, int col);
Matrix *createUnitMatrix(int n);
void finalizeMatrix(Matrix *m);

float *diagonal(Matrix *m);
float *antiDiagonal(Matrix *m);
float *toArray(Matrix *m);
float *sumOfRows(Matrix *m);
float *sumOfCols(Matrix *m);

void copyMatrix(Matrix *dest, Matrix *src);

void scaleRow(Matrix *m, int row, float factor);
void addToRow(Matrix *m, int row, float k);
void scaleCol(Matrix *m, int col, float factor);
void addToCol(Matrix *m, int col, float k);
void scaleMatrix(Matrix *m, float factor);
void addToMatrix(Matrix *m, float k);

float arithmeticMean(Matrix *m);
float matrixSum(Matrix *m);
float findMin(Matrix *m);
float findMax(Matrix *m);

Matrix *matrixInversion(Matrix *m);
Matrix *transpose(Matrix *m);

Matrix *matrixAdd(Matrix *m1, Matrix *m2);
Matrix *matrixSub(Matrix *m1, Matrix *m2);
Matrix *matrixMul(Matrix *m1, Matrix *m2);
Matrix *vectorMul(Matrix *m, Matrix *v);

void swapRows(Matrix *m, int row1, int row2);
void swapCols(Matrix *m, int col1, int col2);
void addRows(Matrix *m, int dest, int src);
void addCols(Matrix *m, int dest, int src);
void subRows(Matrix *m, int dest, int src);
void subCols(Matrix *m, int dest, int src);

void printMatrix(Matrix *m);
void readMatrixFromUser(Matrix *m);

void swapMatrix(Matrix *m1, Matrix *m2);
void fillMatrix(Matrix *m, float num);
void initMatrix(Matrix *m, float num);
#endif