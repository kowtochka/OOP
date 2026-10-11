#include <iostream>
#include <cstdlib>
#include <ctime>
#include "matrix.h"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Matrix a(3, 4);
    a.fillRandom();
    std::cout << "Matrix a:\n";
    a.print();

    Matrix b = a;

    b.set(0, 0, 999);
    std::cout << "\nAfter b.set(0, 0, 999):\n";
    std::cout << "Matrix a:\n";
    a.print();
    std::cout << "Matrix b:\n";
    b.print();

    Matrix c(2, 2);
    c.fillRandom();
    c = a;

    std::cout << "\nMatrix c after c = a:\n";
    c.print();

    Matrix d, e;
    d = e = a;
    std::cout << "\nMatrix d,e after d = e = a:\n";
    std::cout << "\nMatrix d:\n";
    d.print();
    std::cout << "\nMatrix e:\n";
    e.print();

    a = a;
    std::cout << "\nMatrix a after a = a:\n";
    a.print();

    return 0;
}