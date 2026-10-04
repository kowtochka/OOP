#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matrix.h"

int main()
{
    srand(time(0));

    Matrix m1;
    Matrix m2(3);
    Matrix m3(3, 4);
    Matrix m4(2, 3);

    std::cout << "--- M2 (Единичная 3x3) ---\n";
    m2.print();
    std::cout << "\n--- M3 (Нули 3x4) ---\n";
    m3.print();
    std::cout << "\n--- M4 (Нули 2x3) ---\n";
    m4.print();

    for (int i = 0; i < m2.getRows(); ++i)
    {
        for (int j = 0; j < m2.getCols(); ++j)
        {
            m2.set(i, j, i * j);
        }
    }
    std::cout << "\n--- M2 после заполнения (i * j) ---\n";
    m2.print();

    m3.fillRandom();
    std::cout << "\n--- M3 (Случайные числа) ---\n";
    m3.print();

    m4.inputFromKeyboard();
    std::cout << "\n--- M4 (Введенная пользователем) ---\n";
    m4.print();

    std::cout << "\nСумма элементов M3: " << m3.sum() << "\n\n";

    std::cout << "--- Демонстрация исключений ---\n";
    try
    {
        Matrix bad(-1, 5);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Поймано исключение: " << e.what() << '\n';
    }

    try
    {
        m3.get(100, 100);
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Поймано исключение: " << e.what() << '\n';
    }

    std::cout << "\n--- M3 Транспонированная (4x3) ---\n";
    Matrix m3_transposed = m3.transpose();
    m3_transposed.print();

    return 0;
}