#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
    int** data_;
    int rows_;
    int cols_;

    void allocate(int rows, int cols);
    void copyFrom(const Matrix& other);
    void freeMemory();

public:
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);
    ~Matrix();

    Matrix& operator=(const Matrix& other);

    void fillRandom();
    void set(int row, int col, int value);
    int get(int row, int cols) const;
    void print() const;

    int getRows() const;
    int getCols() const;
};

#endif
