#ifndef MATRIX_FLATTEN_MATRIXFLATTEN_H
#define MATRIX_FLATTEN_MATRIXFLATTEN_H

/*
 * Matrix Flatten
 */

class MatrixFlatten {
private:
    int rows{};
    int cols{};
    int depth{};
    int ***matrix{};


public:
    MatrixFlatten();

    MatrixFlatten(int rows, int cols, int depth, int ***matrix);

    MatrixFlatten(int rows, int cols, int depth, int *matrix);

    int *flatten();

    int getIndex(int i, int j, int k) const;

    void printMatrix();

    ~MatrixFlatten();

    static int *** generateMatrix(int rows, int cols, int depth);

    static void printMatrix(int ***mat, int n, int m, int p);

    static void printFlatten(int *mat, int len);

    static int *flatten(int ***mat, int n, int m, int p);

};


#endif //MATRIX_FLATTEN_MATRIXFLATTEN_H
