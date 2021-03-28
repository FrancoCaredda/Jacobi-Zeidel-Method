#ifndef ARRAYS_H
#define ARRAYS_H

//--------------------------------------------------------------------------------
void PrintDoubleMatrix(double **pMatrix, int nRows, int nColumns);
//--------------------------------------------------------------------------------
void PrintDoubleArray(double *pArray, int nLength);
//--------------------------------------------------------------------------------
void EnterDoubleMatrix(double **pMatrix, int nRows, int nColumns);
//--------------------------------------------------------------------------------
void EnterDoubleArray(double *pArray, int nLength);
//--------------------------------------------------------------------------------
void SwapMatrixRows(double **pMatrix, int nFirstRow, 
                    int nSecondRow, int nColumns);
//--------------------------------------------------------------------------------
void CopyMatrix(double **pDestination, double **pSource, int nRows, int nColumns);
//--------------------------------------------------------------------------------
void CopyArray(double *pDestination, double *pSource, int nLength);
//--------------------------------------------------------------------------------
double** GenerateSmallerMatrix(double **pSource, int nRows, int nColumns, 
                           int nExeptedRow, int nExeptedColumn);
//--------------------------------------------------------------------------------
void Swap(double &a, double &b);
//--------------------------------------------------------------------------------

#endif