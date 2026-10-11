#include "matrix.h"
#include <iostream>
#include <cstdlib>

void Matrix::allocate(int rows, int cols)
{
    data_ = new int *[rows];
    for (int i = 0; i < rows; ++i)
    {
        data_[i] = new int[cols];
    }
    rows_ = rows;
    cols_ = cols;
}

void Matrix::copyFrom(const Matrix &other)
{
    if (other.rows_ == 0 || other.cols_ == 0 || other.data_ == nullptr)
    {
        rows_ = 0;
        cols_ = 0;
        data_ = nullptr;
        return;
    }
    allocate(other.rows_, other.cols_);
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            data_[i][j] = other.data_[i][j];
        }
    }
}

void Matrix::freeMemory()
{
    if (data_ != nullptr)
    {
        for (int i = 0; i < rows_; ++i)
        {
            delete[] data_[i];
        }
        delete[] data_;
        data_ = nullptr;
    }
    rows_ = 0;
    cols_ = 0;
}

Matrix::Matrix() : data_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(int rows, int cols) : data_(nullptr), rows_(0), cols_(0)
{
    if (rows <= 0 || cols <= 0)
    {
        return;
    }
    allocate(rows, cols);
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            data_[i][j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix &other) : data_(nullptr), rows_(0), cols_(0)
{
    copyFrom(other);
}

Matrix::~Matrix()
{
    freeMemory();
}

Matrix &Matrix::operator=(const Matrix &other)
{
    if (this == &other)
    {
        return *this;
    }
    freeMemory();
    copyFrom(other);
    return *this;
}

void Matrix::fillRandom()
{
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            data_[i][j] = rand() % 100;
        }
    }
}

void Matrix::set(int row, int col, int value)
{
    if (row >= 0 && row < rows_ && col >= 0 && col < cols_)
    {
        data_[row][col] = value;
    }
}

int Matrix::get(int row, int col) const
{
    if (row >= 0 && row < rows_ && col >= 0 && col < cols_)
    {
        return data_[row][col];
    }
    return 0;
}

void Matrix::print() const
{
    if (rows_ == 0 || cols_ == 0)
    {
        std::cout << "Matrix is empty (0x0)\n";
        return;
    }
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            std::cout << data_[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int Matrix::getRows() const { return rows_; }
int Matrix::getCols() const { return cols_; }