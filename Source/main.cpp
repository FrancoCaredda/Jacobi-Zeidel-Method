#include "../Headers/Memory.h"
#include "../Headers/Arrays.h"
#include "../Headers/Calculations.h"

#include <iostream>

using namespace std;

int main(void) {
    int nDimention = 4;

    double **pMultiplierMatrix = AllocateDoubleMatrix(nDimention, nDimention);
    double *pMembersVector = AllocateDoubleArray(nDimention);

    cout << "Enter coeficient matrix: " << endl;
    EnterDoubleMatrix(pMultiplierMatrix, nDimention, nDimention);
    cout << endl << endl << "Enter members vector: " << endl;
    EnterDoubleArray(pMembersVector, nDimention);

    cout << endl << "Yacobi method" << endl << endl;

    double *pResultVector = Calculation(pMultiplierMatrix, pMembersVector, nDimention, YacobiIterationsFormula);

    if (pResultVector == nullptr) {
        cout << "Roots doesn\'t exist!!!\n";
        return -1;
    }

    cout << "Result: ";
    PrintDoubleArray(pResultVector, nDimention);
    FreeDoubleArray(&pResultVector);

    cout << endl << endl;

    cout << "Zeidel Method" << endl << endl;
    pResultVector = Calculation(pMultiplierMatrix, pMembersVector, nDimention, ZeidelIterationsFormula);

    cout << "Result: ";
    PrintDoubleArray(pResultVector, nDimention);
    FreeDoubleArray(&pResultVector);

    cout << endl << endl;

    FreeDoubleMatrix(pMultiplierMatrix, nDimention);
    FreeDoubleArray(&pMembersVector);
    pMultiplierMatrix = nullptr;

    return 0;
}