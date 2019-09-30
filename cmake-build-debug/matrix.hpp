//
// Created by Alec on 2019-09-30.
//

#ifndef ASSIGNMENT1_MATRIX_HPP
#define ASSIGNMENT1_MATRIX_HPP

using namespace std;

class Matrix{

public:
    Matrix();
    Matrix(double col, double row);

private:
    double col, row;
    double** a;
    void allocateArr(){
         a = new double*[row];
        for(int i = 0; i < row; ++i)
            a[i] = new double[col];
    };

};


#endif //ASSIGNMENT1_MATRIX_HPP
