#include "../Headers/Calculations.h"
#include "../Headers/Arrays.h"
#include "../Headers/Memory.h"

#include <stdio.h>
#include <math.h>

#define EPSILON 0.001

//--------------------------------------------------------------------------------
void YacobiIterationsFormula(double **pMatrix, 
                              double *pVector, 
                              double *pPreviousVector,
                              double *pResult) {
    pResult[0] = (  pVector[0] - (pMatrix[0][1] * pPreviousVector[1] + 
                    pMatrix[0][2] * pPreviousVector[2] + 
                    pMatrix[0][3] * pPreviousVector[3])  ) / pMatrix[0][0];
    
    pResult[1] = (  pVector[1] - (pMatrix[1][0] * pPreviousVector[0] + 
                    pMatrix[1][2] * pPreviousVector[2] + 
                    pMatrix[1][3] * pPreviousVector[3])  ) / pMatrix[1][1];
    
    pResult[2] = (  pVector[2] - (pMatrix[2][0] * pPreviousVector[0] + 
                    pMatrix[2][1] * pPreviousVector[1] + 
                    pMatrix[2][3] * pPreviousVector[3])  ) / pMatrix[2][2];
    
    pResult[3] = (  pVector[0] - (pMatrix[3][0] * pPreviousVector[0] + 
                    pMatrix[3][1] * pPreviousVector[1] + 
                    pMatrix[3][2] * pPreviousVector[2])  ) / pMatrix[3][3];
}
//--------------------------------------------------------------------------------
void ZeidelIterationsFormula(double **pMatrix, 
                              double *pVector, 
                              double *pPreviousVector,
                              double *pResult) {
    pResult[0] = (  pVector[0] - (pMatrix[0][1] * pPreviousVector[1] + 
                    pMatrix[0][2] * pPreviousVector[2] + 
                    pMatrix[0][3] * pPreviousVector[3])  ) / pMatrix[0][0];
    
    pResult[1] = (  pVector[1] - (pMatrix[1][0] * pResult[0] + 
                    pMatrix[1][2] * pPreviousVector[2] + 
                    pMatrix[1][3] * pPreviousVector[3])  ) / pMatrix[1][1];
    
    pResult[2] = (  pVector[2] - (pMatrix[2][0] * pResult[0] + 
                    pMatrix[2][1] * pResult[1] + 
                    pMatrix[2][3] * pPreviousVector[3])  ) / pMatrix[2][2];
    
    pResult[3] = (  pVector[0] - (pMatrix[3][0] * pResult[0] + 
                    pMatrix[3][1] * pResult[1] + 
                    pMatrix[3][2] * pResult[2])  ) / pMatrix[3][3];
}
//--------------------------------------------------------------------------------
static double DeltaVector(double *pCurrentVector, double *pPreviousVector,
                            int nDimention) {
    double rSum = 0;
    for (int i = 0; i < nDimention; i++)
        rSum += fabs(pCurrentVector[i] - pPreviousVector[i]);

    return rSum;
}
//--------------------------------------------------------------------------------
double* Calculation(double **pMultiplierMatrix, double *pMemberVector,
                          int nDimention, pCalculation calculation) {

    // if (!IsConvergentProcess(pMultiplierMatrix, nDimention))
    //     return nullptr;

    double *pPreviousVector = AllocateDoubleArray(nDimention);
    double *pResultVector = AllocateDoubleArray(nDimention);

    CopyArray(pPreviousVector, pMemberVector, nDimention);

    double rDelta = 0;

    int count = 0;
    do {
        count++;
        calculation(pMultiplierMatrix, 
                          pMemberVector, 
                          pPreviousVector, 
                          pResultVector);
        rDelta = DeltaVector(pResultVector, pPreviousVector, nDimention);

        printf("Iteration#%3d | previous vector: ", count);
        PrintDoubleArray(pPreviousVector, nDimention);
        printf(" | current vector: ");
        PrintDoubleArray(pResultVector, nDimention);
        printf(" | delta: %10lf |\n", rDelta);

        CopyArray(pPreviousVector, pResultVector, nDimention);
    } while (rDelta > EPSILON);

    printf("\n\nIterations: %d\n\n", count);
    FreeDoubleArray(&pPreviousVector);
    
    return pResultVector;
}
//--------------------------------------------------------------------------------