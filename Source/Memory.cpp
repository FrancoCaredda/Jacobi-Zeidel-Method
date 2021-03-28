#include "../Headers/Arrays.h"

//--------------------------------------------------------------------------------
double** AllocateDoubleMatrix(int nRows, int nColumns) {
    double** pMatrix = new double*[nRows];

    for (int i = 0; i < nRows; i++)
        pMatrix[i] = new double[nColumns];

    return pMatrix;
}
//--------------------------------------------------------------------------------
double* AllocateDoubleArray(int nLength) {
    return new double[nLength];
}
//--------------------------------------------------------------------------------
void FreeDoubleMatrix(double **pMatrix, int nRows) {
    for (int i = 0; i < nRows; i++)
        delete [] pMatrix[i];

    delete [] pMatrix;
}
//--------------------------------------------------------------------------------
void FreeDoubleArray(double **pArray) {
    delete [] *pArray;
    pArray = nullptr;
}
//--------------------------------------------------------------------------------