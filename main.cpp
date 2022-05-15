#include <iostream>
#include "MatrixFlatten.h"

using namespace std;

int main() {

    int ***test = MatrixFlatten::generateMatrix(3, 2, 4);

    MatrixFlatten matrixFlatten = MatrixFlatten(3, 2, 4, test);

    matrixFlatten.printMatrix();

    int *flat = matrixFlatten.flatten();
    cout << "Flattened matrix: " << endl;
    for (int i = 0; i < 3 * 2 * 4; i++) {
        cout << flat[i] << " ";
    }

    cout << endl;
    cout << endl;
    cout << "Index Mapping: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 4; k++) {
                cout << flat[matrixFlatten.getIndex(i, j, k)] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    matrixFlatten.getIndex(1, 1, 1);

    return 0;
}
