#include "../Headers/Arrays.h"
#include "../Headers/Memory.h"

#include <stdio.h>

//--------------------------------------------------------------------------------
void Swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}
//--------------------------------------------------------------------------------
void PrintDoubleMatrix(double **pMatrix, int nRows, int nColumns) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nColumns; j++) {
            printf("%5lf ", pMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
//--------------------------------------------------------------------------------
void PrintDoubleArray(double *pArray, int nLength) {
    for (int i = 0; i < nLength; i++)
        printf("%10lf ", pArray[i]);
}
//--------------------------------------------------------------------------------
void EnterDoubleMatrix(double **pMatrix, int nRows, int nColumns) {
    for (int i = 0; i < nRows; i++) {
        printf("Enter row #%d: ", i + 1);
        for (int j = 0; j < nColumns; j++) {
            scanf("%lf", &pMatrix[i][j]);
        }
    }
}
//--------------------------------------------------------------------------------
void EnterDoubleArray(double *pArray, int nLength) {
    for (int i = 0; i < nLength; i++)
        scanf("%lf", &pArray[i]);
}
//--------------------------------------------------------------------------------
void SwapMatrixRows(double **pMatrix, 
                    int nFirstRow, 
                    int nSecondRow, 
                    int nColumns) {
    for (int i = 0; i < nColumns; i++)
        Swap(pMatrix[nFirstRow][i], pMatrix[nSecondRow][i]);
}
//--------------------------------------------------------------------------------
void CopyMatrix(double **pDestination, double **pSource, 
                int nRows, int nColumns) {
    for (int i = 0; i < nRows; i++) {
        for (int j = 0; j < nColumns; j++)
            pDestination[i][j] = pSource[i][j];
    }
}
//--------------------------------------------------------------------------------
void CopyArray(double *pDestination, double *pSource, int nLength) {
    for (int i = 0; i < nLength; i++)
        pDestination[i] = pSource[i];
}
//--------------------------------------------------------------------------------
double** GenerateSmallerMatrix(double **pSource, int nRows, int nColumns, 
                           int nExeptedRow, int nExeptedColumn) {
    int k = 0; 
    int s = 0;

    double **pNewMatrix = AllocateDoubleMatrix(nRows - 1, nColumns - 1);

    for (int i = 0; i < nRows; i++) {
        if (i != nExeptedRow) {
            for (int j = 0; j < nColumns; j++) {
                if (j != nExeptedColumn) {
                    pNewMatrix[k][s] = pSource[i][j];
                    s++;
                }
            }
            s = 0;
            k++;
        }
    }
    
    return pNewMatrix;
}
//--------------------------------------------------------------------------------