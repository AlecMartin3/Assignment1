//
// Created by Alec on 2019-09-30.
//

#ifndef ASSIGNMENT1_MATRIX_HPP
#define ASSIGNMENT1_MATRIX_HPP
#include <iostream>
using namespace std;

class Matrix{

public:
    Matrix();
    Matrix(int row, int col);
    Matrix(int n);
    Matrix(double arr[], int n);
    Matrix(const Matrix& N);
    void set_value( int row, int col, double newVal);
    double get_value(int row,int col) const;
    void clear();
    ~Matrix();
    int getRow() const;
    int getCol() const;
    friend ostream& operator<<(ostream& os, const Matrix& mat);
    friend bool operator==( Matrix& mat1, Matrix& mat2);
    friend bool operator!=( Matrix& mat1, Matrix& mat2);
    Matrix& operator++();
    Matrix operator++(int);
    Matrix& operator--();
    Matrix operator--(int);
    Matrix& operator=(Matrix mat);
    friend void mySwap(Matrix &mat1, Matrix &mat2);
    friend Matrix operator+(const Matrix& mat1,const Matrix& mat2);
    Matrix& operator+=(Matrix &mat);
    friend Matrix operator-(const Matrix& mat1, const Matrix& mat2);
    Matrix& operator-=(Matrix& mat);
    friend Matrix operator*(const Matrix& mat1, const Matrix& mat2);
    Matrix& operator*=(const Matrix& mat);


private:
    int col, row;
    double** a;
    void allocateArr(){
         a = new double*[row];
        for(int i = 0; i < row; ++i)
            a[i] = new double[col];
    };
};


#endif //ASSIGNMENT1_MATRIX_HPP
