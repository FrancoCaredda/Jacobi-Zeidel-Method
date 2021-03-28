#ifndef CALCULATIONS_H
#define CALCULATIONS_H

typedef void(*pCalculation)(double**, double*, double*, double*);

//--------------------------------------------------------------------------------
void YacobiIterationsFormula(double **pMatrix, 
                              double *pVector, 
                              double *pPreviousVector,
                              double *pResult);
//--------------------------------------------------------------------------------
void ZeidelIterationsFormula(double **pMatrix, 
                              double *pVector, 
                              double *pPreviousVector,
                              double *pResult);
//--------------------------------------------------------------------------------                           
double* Calculation(double **pMultiplierMatrix, double *pMemberVector,
                          int nDimention, pCalculation calculation);
//--------------------------------------------------------------------------------

#endif