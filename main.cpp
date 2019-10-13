#include <iostream>
#include "matrix.hpp"
int main() {
    int d1 = 1;
    int d2 = 5;

    int d3 = 1;
    int d4 = 5;

    Matrix matrix1(d1, d2);
    std::cout << "Matrix 1" << std::endl;
    for(int i = 0; i < d1; ++i)
    {
        for(int j = 0; j < d2; ++j)
        {
            matrix1.set_value(i,j, 1.0);
        }
    }
    cout << matrix1 << endl;

    Matrix matrix2(d3, d4);
    for(int i = 0; i < d3; ++i)
    {
        for(int j = 0; j < d4; ++j)
        {
            matrix2.set_value(i,j, 2.0);
        }
    }
    cout << "Matrix2" << endl;
    cout << matrix2 << endl;

    cout << "Matrix2 = Matrix1" << endl;
    matrix2 = matrix1;
    cout << matrix2 << endl;
    cout << matrix1 << endl;


    cout << "matrix 1 + matrix 2" << endl;
    cout << (matrix1 + matrix2) << endl;
    cout << matrix2 << endl;
    cout << matrix1 << endl;

    std::cout << "Matrix 3 = 1 + 2" << std::endl;
    Matrix matrix3 = matrix1 + matrix2;
    cout << matrix3 << endl;

    std::cout << "Matrix ++3" << std::endl;
    ++matrix3;
    cout << matrix3 << endl;

    std::cout << "Matrix ++3 in cout" << std::endl;
    cout << ++matrix3 << endl;

    std::cout << "Matrix 3++" << std::endl;
    matrix3++;
    cout << matrix3 << endl;


    std::cout << "Matrix 3++ in cout" << std::endl;
    cout << matrix3++ << endl;

    cout << matrix3 << endl;
    if(matrix3 ==  matrix2){
        std::cout << "This should never appear" << std::endl;
    }else {
        std::cout << "matrix 3 does not equal matrix 2 (using ==)" << std::endl;
    }

    if(matrix3 != matrix2){
        std::cout << "matrix 3 does not equal matrix 2 (using !=)" << std::endl;
    }else{
        std::cout << "This should never appear" << std::endl;
    }

    if(matrix1 ==  matrix2){
        std::cout << "matrix 1 equals matrix 2 (using ==)" << std::endl;
    }else{
        std::cout << "This should never appear" << std::endl;
    }

    if(matrix1 != matrix2){
        std::cout << "This should never appear" << std::endl;
    }else{
        std::cout << "matrix 1 equals matrix 2 (using !=)" << std::endl;

    }

    cout << "\n";
    std::cout << "Matrix with n" << std::endl;
    Matrix matrix4(2);
    cout << matrix4 << endl;

    std::cout << "Square Matrix" << std::endl;
    double mat5 [9] = {1,2,1,2,1,2,1,2};
    Matrix matrix5(mat5, 1);
    cout << matrix5 << endl;

    std::cout << "Square Matrix 2" << std::endl;
    double mat6 [4] = {1.0,2.0,3.0,4.0};
    Matrix matrix6(mat6, 4);
    cout << matrix6 << endl;

    std::cout << "Square Matrix *= Square Matrix" << std::endl;
    double mat7[4] = {1.0,2.0,3.0,4.0};
    Matrix matrix7(mat7, 4);
    matrix6 *= matrix7;
    cout << matrix6 << endl;

    std::cout << "Checking if *= concats the matrix and that it works" << std::endl;
    Matrix matrix10(1, 2);
    std::cout << "Matrix 10" << std::endl;
    for(int i = 0; i < 1; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            matrix10.set_value(i,j, 3.2);
        }
    }
    matrix10 *= matrix7;
    cout << matrix10 << endl;

    std::cout << "Checking if * concats the matrix and that it works in cout" << std::endl;
    Matrix zz = matrix10 * matrix7;
    cout <<  (matrix10 * matrix7) << endl;

    return 0;
}
