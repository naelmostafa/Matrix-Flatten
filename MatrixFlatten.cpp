#include <cstdlib>
#include <iostream>
#include "MatrixFlatten.h"

using namespace std;

MatrixFlatten::MatrixFlatten() = default;

MatrixFlatten::MatrixFlatten(int rows, int cols, int depth, int ***matrix) {
    this->rows = rows;
    this->cols = cols;
    this->depth = depth;
    this->matrix = matrix;
}

MatrixFlatten::MatrixFlatten(int rows, int cols, int depth, int *matrix) {
    this->rows = rows;
    this->cols = cols;
    this->depth = depth;
    this->matrix = new int **[rows];
    for (int i = 0; i < rows; i++) {
        this->matrix[i] = new int *[cols];
        for (int j = 0; j < cols; j++) {
            this->matrix[i][j] = new int[depth];
            for (int k = 0; k < depth; k++) {
                this->matrix[i][j][k] = matrix[getIndex(i, j, k)];
            }
        }
    }
}

int *MatrixFlatten::flatten() {
    int *flat = new int[rows * cols * depth];
    int index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = 0; k < depth; k++) {
                flat[index] = matrix[i][j][k];
                index++;
            }
        }
    }
    return flat;
}

MatrixFlatten::~MatrixFlatten() {
    delete[] matrix;
}


void MatrixFlatten::printMatrix() {
    cout << "Printing matrix:" << endl;
    cout << "{ " << endl;
    for (int i = 0; i < rows; i++) {
        cout << "\t{ " << endl;
        for (int j = 0; j < cols; j++) {
            cout << "\t\t{";
            for (int k = 0; k < depth; k++) {
                cout << matrix[i][j][k] << " ";
            }
            cout << "}," << endl;
        }
        cout << "\t}" << endl;
    }
    cout << "}" << endl;
}


int MatrixFlatten::getIndex(int i, int j, int k) const {
    return i * cols * depth + j * depth + k;
}

int ***MatrixFlatten::generateMatrix(int n, int m, int p) {
    int ***mat = new int **[n];
    for (int i = 0; i < n; i++) {
        mat[i] = new int *[m];
        for (int j = 0; j < m; j++) {
            mat[i][j] = new int[p];
            for (int k = 0; k < p; k++) {
                mat[i][j][k] = rand() % 10;
            }
        }
    }
    return mat;
}


int *MatrixFlatten::flatten(int ***mat, int n, int m, int p) {
    int *flat = new int[n * m * p];
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                flat[index] = mat[i][j][k];
                index++;
            }
        }
    }
    return flat;
}

void MatrixFlatten::printMatrix(int ***mat, int n, int m, int p) {
    cout << "Printing matrix" << endl;
    cout << "{ " << endl;
    for (int i = 0; i < n; i++) {
        cout << "\t{ " << endl;
        for (int j = 0; j < m; j++) {
            cout << "\t\t{";
            for (int k = 0; k < p; k++) {
                cout << mat[i][j][k] << " ";
            }
            cout << "}," << endl;
        }
        cout << "\t}" << endl;
    }
    cout << "}" << endl;
}

void MatrixFlatten::printFlatten(int *mat, int len) {
    for (int i = 0; i < len; i++) {
        std::cout << mat[i] << " ";
    }
    std::cout << std::endl;
}







