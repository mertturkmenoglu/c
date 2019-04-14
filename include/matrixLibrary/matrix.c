#include "matrix.h"
#include <stdio.h>



Matrix *createMatrix(int row, int col) {
    Matrix *m = (Matrix*) malloc(sizeof(Matrix));
    m->row = row;
    m->col = col;
    m->matrix = (float**) malloc(m->row * m->col * sizeof(float*));
    int i;
    for(i = 0; i < row; i++) {
        m->matrix[i] = (float*) malloc(m->col * sizeof(float));
    }
    return m;
}



Matrix *createUnitMatrix(int n) {
    Matrix *m = createMatrix(n, n);
    initMatrix(m, 0);
    int i;
    for(i = 0; i < n; i++)
        m->matrix[i][i] = 1;
    return m;
}



void finalizeMatrix(Matrix *m) {
    // TODO: Implement function
}



float *diagonal(Matrix *m) {
    float *array = (float*) malloc(m->row * sizeof(float));
    int i;
    for(i = 0; i < m->row; i++)
        array[i] = m->matrix[i][i];
    return array;
}



float *antiDiagonal(Matrix *m) {
    int i;
    float *array = (float*) malloc(m->row * sizeof(float));
    for(i = m->row - 1; i >= 0; i--) {
        array[m->row - 1 - i] = m->matrix[m->row - 1 - i][i];
    }
    return array;
}



float *toArray(Matrix *m) {
    int i, j;
    float *array = (float*) malloc(m->row * m->col * sizeof(float));
    for(i = 0; i < m->row; i++) {
        for(j = 0; j < m->col; j++) {
            array[i * m->col + j] = m->matrix[i][j];
        }
    }
    return array;
}



float *sumOfRows(Matrix *m) {
    float *array = (float*) malloc(m->row * sizeof(float));
    float sum;
    int i, j;
    for(i = 0; i < m->row; i++) {
        sum = 0;
        for(j = 0; j < m->col; j++) {
            sum += m->matrix[i][j];
        }
        array[i] = sum;
    }
    return array;
}



float *sumOfCols(Matrix *m) {
    float *array = (float*) malloc(m->col * sizeof(float));
    float sum;
    int i, j;
    for(i = 0; i < m->col; i++) {
        sum = 0;
        for(j = 0; j < m->row; j++) {
            sum += m->matrix[j][i];
        }
        array[i] = sum;
    }
    return array;
}



void copyMatrix(Matrix *dest, Matrix *src) {
    int i, j;
    for(i = 0; i < dest->row; i++) {
        for(j = 0; j < dest->col; j++)
            dest->matrix[i][j] = src->matrix[i][j];
    }
}



void scaleRow(Matrix *m, int row, float factor) {
    int i;
    for(i = 0; i < m->col; i++)
        m->matrix[row][i] *= factor;
}



void addToRow(Matrix *m, int row, float k) {
    int i;
    for(i = 0; i < m->col; i++)
        m->matrix[row][i] += k;
}



void scaleCol(Matrix *m, int col, float factor) {
    int i;
    for(i = 0; i < m->row; i++)
        m->matrix[col][i] *= factor;
}
void addToCol(Matrix *m, int col, float k) {
    int i;
    for(i = 0; i < m->row; i++)
        m->matrix[col][i] += k;
}



void scaleMatrix(Matrix *m, float factor) {
    int i;
    for(i = 0; i < m->row; i++)
        scaleRow(m, i, factor);
}



void addToMatrix(Matrix *m, float k) {
    int i;
    for(i = 0; i < m->row; i++)
        scaleRow(m, i, k);
}



float arithmeticMean(Matrix *m) {
    float sum = matrixSum(m);
    return (sum / (m->row * m->col));
}



float matrixSum(Matrix *m) {
    float sum = 0;
    int i, j;
    for(i = 0; i < m->row; i++) {
        for(j = 0; j < m->col; j++)
            sum += m->matrix[i][j];
    }
    return sum;
}



float findMin(Matrix *m) {
    int i, j;
    float min = m->matrix[0][0];
    for(i = 0; i < m->row; i++) {
        for(j = 0; j < m->col; j++) {
            if(m->matrix[i][j] < min)
                min = m->matrix[i][j];
        }
    }
    return min;
}



float findMax(Matrix *m) {
    int i, j;
    float max = m->matrix[0][0];
    for(i = 0; i < m->row; i++) {
        for(j = 0; j < m->col; j++) {
            if(m->matrix[i][j] > max)
                max = m->matrix[i][j];
        }
    }
    return max;
}



Matrix *matrixInversion(Matrix *m) {
    // TODO: Implement function
}



Matrix *transpose(Matrix *m) {
    Matrix *t = createMatrix(m->col, m->row);
    int i, j;
    for(i = 0; i < m->row; i++) {
        for(j = 0; j < m->col; j++)
            t->matrix[j][i] = m->matrix[i][j];
    }
    return t;
}



Matrix *matrixAdd(Matrix *m1, Matrix *m2) {
    Matrix *s = createMatrix(m1->row, m1->col);
    int i, j;
    for(i = 0; i < m1->row; i++) {
        for(j = 0; j < m1->col; j++)
            s->matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
    }
    return s;
}



Matrix *matrixSub(Matrix *m1, Matrix *m2) {
    Matrix *s = createMatrix(m1->row, m1->col);
    int i, j;
    for(i = 0; i < m1->row; i++) {
        for(j = 0; j < m1->col; j++)
            s->matrix[i][j] = m1->matrix[i][j] - m2->matrix[i][j];
    }
    return s;
}



Matrix *matrixMul(Matrix *m1, Matrix *m2) {
    // TODO: Implement function
}



Matrix *vectorMul(Matrix *m, Matrix *v) {
    return matrixMul(m, v);
}



void swapRows(Matrix *m, int row1, int row2) {
    int i;
    float temp;
    for(i = 0; i < m->col; i++) {
        temp = m->matrix[row1][i];
        m->matrix[row1][i] = m->matrix[row2][i];
        m->matrix[row2][i] = temp;
    }
}



void swapCols(Matrix *m, int col1, int col2) {
    int i;
    float temp;
    for(i = 0; i < m->row; i++) {
        temp = m->matrix[i][col1];
        m->matrix[i][col1] = m->matrix[i][col2];
        m->matrix[i][col2] = temp;
    }
}



void addRows(Matrix *m, int dest, int src) {
    int i;
    for(i = 0; i < m->col; i++)
        m->matrix[dest][i] += m->matrix[src][i];
}



void addCols(Matrix *m, int dest, int src) {
    int i;
    for(i = 0; i < m->row; i++)
        m->matrix[i][dest] += m->matrix[i][src];
}



void subRows(Matrix *m, int dest, int src) {
    int i;
    for(i = 0; i < m->col; i++)
        m->matrix[dest][i] -= m->matrix[src][i];
}



void subCols(Matrix *m, int dest, int src) {
    int i;
    for(i = 0; i < m->row; i++)
        m->matrix[i][dest] -= m->matrix[i][src];
}



void printMatrix(Matrix *m) {
    int i, j;
    for(i = 0; i < m->row; i++) {
        for(j = 0; j < m->col; j++)
            printf("%f\t", m->matrix[i][j]);
        printf("\n");
    }
}



void readMatrixFromUser(Matrix *m) {
    int i, j;
    for(i = 0; i < m->row; i++) {
        for(j = 0; j < m->col; j++) {
            printf("\nMatrix[%d][%d]: ", i, j);
            scanf("%f", &m->matrix[i][j]);
        }
    }
}



void swapMatrix(Matrix *m1, Matrix *m2) {
    Matrix *temp = createMatrix(m1->row, m1->col);
    temp = m1;
    m1 = m2;
    m2 = temp;
    finalizeMatrix(temp);
}



void fillMatrix(Matrix *m, float num) {
    int i, j;
    for(i = 0; i < m->row; i++) {
        for(j = 0; j < m->col; j++)
            m->matrix[i][j] = num;
    }
}



void initMatrix(Matrix *m, float num) {
    fillMatrix(m, num);
}