//
// Created by Alec on 2019-09-30.
//
#include <iostream>
#include <sstream>
#include <cmath>
#include "matrix.hpp"


Matrix:: Matrix(): Matrix(1,1){
}
Matrix:: Matrix(int n): Matrix(n,n){
}
Matrix:: Matrix(int col, int row){
    if( col <= 0  || row <= 0 ) {
        throw "row/col is zero or negative";
    }
    Matrix::col = col;
    Matrix::row = row;
    allocateArr();
    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
        {
            a[i][j] = 0;
        }
    }
};
Matrix::Matrix(double arr[]) {
    long double sr = sqrt(sizeof(arr));
    int k = 0;
    for(int i = 0; i < sr; i++)
    {
        for(int j = 0; j < sr; j++)
        {
            //TODO: THIS MAY IS WRONG SO FIX IT LATER? MAYBE?
            a[i][j] = arr[k];
            k++;
        }
    }
}
void Matrix::set_value(int col, int row, double newVal){
    if( col < 0  || row < 0 ) {
            throw "row/col is zero or negative";
    }
    //TODO: Check if this works
    if(col > Matrix::col || row > Matrix::row){
        throw "row/col is too big";
    }
    a[col][row] = newVal;
}

double Matrix::get_value(int col, int row) const{
    if( col < 0  || row < 0 ) {
        throw "row/col is zero or negative";
    }
    //TODO: Check if this works
    if(col > Matrix::col || row > Matrix::row){
        throw "row/col is too big";
    }
    double val = a[col][row];
    return val;
}

void Matrix::clear(){
    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
        {
            a[i][j] = 0;
        }
    }
}

Matrix:: ~Matrix(){
    for(int i; i < col; i++){
        delete[] a[i];
    }
    delete[] a;
}

int Matrix::getCol() const {
    return col;
}
int Matrix::getRow() const{
    return row;
}


ostream& operator<<(ostream& os, const Matrix& mat)
{
    for(int i = 0; i < mat.col; i++){
        for(int j = 0; j < mat.row; j++){
            os << mat.a[i][j] << "  ";
        }
        os << '\n';
    }
}

bool operator==(const Matrix& mat1, const Matrix& mat2)
{
    if(mat1.col != mat2.col || mat1.row != mat2.row){
        return false;
    }
    for(int i = 0; i < mat1.col; i++){
        for(int j = 0; j < mat1.row; j++){
            int tolerance = mat1.a[i][j] - mat2.a[i][j];
            if (tolerance > 0.001 || tolerance < 0.001){
                return false;
            }
        }
    }
    return true;
}
bool operator!=(const Matrix& mat1, const Matrix& mat2){
    return !operator==(mat1,mat2);
}

Matrix& Matrix:: operator++(){
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            a[i][j] = a[i][j] + 1.00;
        }
    }
}
Matrix& Matrix:: operator++(int){
    Matrix tmp(*this);
    operator++();
    return tmp;
}
Matrix& Matrix:: operator--(){
    for(int i = 0; i < col; i++){
        for(int j = 0; j < row; j++){
            a[i][j] = a[i][j] - 1.00;
        }
    }
    return *this;
}
Matrix& Matrix:: operator--(int){
    Matrix tmp(*this);
    operator--();
    return tmp;
}

// TODO: copy assignment operator
Matrix& Matrix:: operator=(const Matrix& mat){
    mySwap(*this, mat);
    return *this;
}

void mySwap(Matrix& mat1, Matrix& mat2){
    using std::swap;

}

Matrix& operator+(const Matrix& mat1, const Matrix& mat2){
    Matrix m;
    if (mat1.col != mat2.col || mat1.row != mat2.row){
        throw "Size of matrices are not the same";
    }
    for(int i = 0; i < mat1.col; i++){
        for(int j = 0; j < mat1.row; j++){
            m.a[i][j] = mat1.a[i][j] + mat2.a[i][j];
        }
    }
    return m;
}

Matrix& operator-(const Matrix& mat1, const Matrix& mat2){
    Matrix m;
    if (mat1.col != mat2.col || mat1.row != mat2.row){
        throw "Size of matrices are not the same";
    }

    for(int i = 0; i < mat1.col; i++){
        for(int j = 0; j < mat1.row; j++){
            m.a[i][j] = mat1.a[i][j] - mat2.a[i][j];
        }
    }
    return m;
}

