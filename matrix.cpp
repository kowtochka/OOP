#include "Matrix.h"
#include <iostream>
#include <cstdlib>

Matrix::Matrix() : data_(nullptr), rows_(0), cols_(0) {}

Matrix::Matrix(int size) : data_(nullptr), rows_(size), cols_(size)
{
    if (size < 0)
    {
        printf("\Матрица не может быть отрицательного размера\n");
    }
    if (size == 0)
        return;

    data_ = new int *[rows_];
    for (int i = 0; i < rows_; ++i)
    {
        // Выделение памяти с нулевой инициализацией {}
        data_[i] = new int[cols_]{};
        data_[i][i] = 1; // Главная диагональ = 1
    }
}

// 3. Конструктор с двумя параметрами (rows x cols)
Matrix::Matrix(int rows, int cols) : data_(nullptr), rows_(rows), cols_(cols)
{
    if (rows < 0 || cols < 0)
    {
        printf("\Матрица не может быть отрицательного размера\n");
    }
    if (rows == 0 || cols == 0)
    {
        rows_ = 0;
        cols_ = 0;
        return;
    }

    data_ = new int *[rows_];
    for (int i = 0; i < rows_; ++i)
    {
        data_[i] = new int[cols_]{};
    }
}

// Деструктор (освобождение памяти)
Matrix::~Matrix()
{
    if (data_ == nullptr)
        return;

    for (int i = 0; i < rows_; ++i)
    {
        delete[] data_[i];
    }
    delete[] data_;
}

int Matrix::get(int i, int j) const
{
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_)
    {
        printf("\nИндекса не существует\n");
    }
    return data_[i][j];
}

void Matrix::set(int i, int j, int value)
{
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_)
    {
        printf("\nИндекса не существует\n");
    }
    data_[i][j] = value;
}

void Matrix::inputFromKeyboard()
{
    std::cout << "Введите " << rows_ * cols_ << " чисел:\n";
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            std::cin >> data_[i][j];
        }
    }
}

void Matrix::fillRandom()
{
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            data_[i][j] = std::rand() % 100;
        }
    }
}

void Matrix::print() const
{
    if (rows_ == 0 || cols_ == 0)
    {
        std::cout << "матрица пуста\n";
        return;
    }
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            std::cout << data_[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

int Matrix::sum() const
{
    int total = 0;
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            total += data_[i][j];
        }
    }
    return total;
}

int Matrix::getRows() const { return rows_; }
int Matrix::getCols() const { return cols_; }

Matrix Matrix::transpose() const
{
    Matrix result(cols_, rows_);
    for (int i = 0; i < rows_; ++i)
    {
        for (int j = 0; j < cols_; ++j)
        {
            result.set(j, i, data_[i][j]);
        }
    }
    return result;
}