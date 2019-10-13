//
// Created by Alec on 2019-09-30.
//
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include "matrix.hpp"


Matrix:: Matrix(): Matrix(1,1){
}
Matrix:: Matrix(int n): Matrix(n,n){
}
Matrix:: Matrix( int row, int col){
    if( col <= 0  || row <= 0 ) {
        throw "row/col is zero or negative";
    }
    Matrix::col = col;
    Matrix::row = row;
    allocateArr();
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            set_value(i,j,0);
        }
    }
};
Matrix::Matrix(double arr[], int n) {
    int sr = sqrt(n);
    if ((sr * sr) != n) {
        throw "Not a square";
    }
    else{
        sr = (floor(sr));
        Matrix::col = sr;
        Matrix::row = sr;

        int k = 0;
        allocateArr();
        for(int i = 0; i < sr; i++)
        {
            for(int j = 0; j < sr; j++)
            {
                set_value(i,j, arr[k]);
                k++;
            }
        }
    }

}
Matrix:: Matrix(const Matrix& N)
{
    row = N.row;
    col = N.col;

    if ( N.a )
    {
        a = new double*[row];

        for (int i = 0; i < row; i++)
            a[i] = new double[col];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                a[i][j] = N.a[i][j];
            }
        }
    }
}
void Matrix::set_value(int row,int col, double newVal){
    if( col < 0  || row < 0 ) {
            throw "row/col is zero or negative";
    }
    if(col > Matrix::col || row > Matrix::row){
        throw "row/col is too big";
    }
    a[row][col] = newVal;
}

double Matrix::get_value(int row, int col) const{
    if( col < 0  || row < 0 ) {
        throw "row/col is zero or negative";
    }
    if(col > Matrix::col || row > Matrix::row){
        throw "row/col is too big";
    }
    double num = a[row][col];
    return num;

}

void Matrix::clear(){
    for(int i = 0; i < getRow(); i++){
        for(int j = 0; j < getCol(); j++){
            set_value(i,j,0);
        }
    }
}

Matrix::~Matrix()
{
    for(int i = 0; i < row; i++)
    {
        delete [] a[i];
    }
    delete [] a;
}

int Matrix::getCol() const {
    return col;
}
int Matrix::getRow() const{
    return row;
}


ostream& operator<<(ostream& os, const Matrix& mat)
{
    for(int i = 0; i < mat.getRow(); ++i){
        for(int j = 0; j < mat.getCol(); ++j){
            os << fixed << setprecision(2) << mat.get_value(i, j) << " ";
        }
        os << "\n";
    }
    return os;
}

bool operator==( const Matrix& mat1, const Matrix& mat2)
{
    if(mat1.getCol() != mat2.getCol() || mat1.getRow() != mat2.getRow()){
        return false;
    }
    for(int i = 0; i < mat1.getRow(); i++){
        for(int j = 0; j < mat1.getCol(); j++){
            double tolerance = mat1.get_value(i,j) - mat2.get_value(i,j);
            if (tolerance > 0.001 || tolerance < -0.001){
                return false;
            }
        }
    }
    return true;
}
bool operator!=( const Matrix& mat1,  const Matrix& mat2){
    return !operator==(mat1,mat2);
}

Matrix& Matrix:: operator++(){
    for(int i = 0; i < getRow(); i++){
        for(int j = 0; j < getCol(); j++){
            set_value(i,j, (get_value(i , j) + 1.00));
        }
    }
    return *this;
}
Matrix Matrix:: operator++(int){
    Matrix tmp(*this);
    operator++();
    return tmp;
}
Matrix& Matrix:: operator--(){
    for(int i = 0; i < getRow(); i++){
        for(int j = 0; j < getCol(); j++){
            set_value(i,j, (get_value(i , j) - 1.00));
        }
    }
    return *this;
}
Matrix Matrix:: operator--(int){
    Matrix tmp(*this);
    operator--();
    return tmp;
}

void mySwap(Matrix& mat1, Matrix& mat2){
    using std::swap;
    swap(mat1.a, mat2.a);
    swap(mat1.row, mat2.row);
    swap(mat1.col, mat2.col);
}

Matrix& Matrix:: operator=(Matrix mat){
    mySwap(*this, mat);
    return *this;
}

Matrix& Matrix:: operator+=(Matrix &mat){
    if (mat.getCol() != getCol() || mat.getRow() != getRow()){
        throw "Size of matrices are not the same";
    }
    for(int i = 0; i < mat.getRow(); i++){
        for(int j = 0; j < mat.getCol(); j++){
            set_value(i,j, (get_value(i,j) + mat.get_value(i,j)));
        }
    }
    return *this;
}

Matrix operator+(const Matrix& mat1,const Matrix& mat2){

    if (mat1.getCol() != mat2.getCol() || mat1.getRow() != mat2.getRow()){
        throw "Size of matrices are not the same";
    }
    Matrix m(mat1.getRow(), mat1.getCol());
    for(int i = 0; i < mat1.getRow(); i++){
        for(int j = 0; j < mat1.getCol(); j++){
            m.set_value(i,j, (mat1.get_value(i,j) + mat2.get_value(i,j)));
        }
    }
    return m;
}

Matrix& Matrix::operator-=( Matrix& mat){
    if (mat.getCol() != getCol() || mat.getRow() != getRow()){
        throw "Size of matrices are not the same";
    }
    for(int i = 0; i < mat.getRow(); i++){
        for(int j = 0; j < mat.getCol(); j++){
            set_value(i,j, (get_value(i,j) - mat.get_value(i,j)));
        }
    }
    return *this;
}

Matrix operator-(const Matrix& mat1,  const Matrix& mat2){
    if (mat1.getCol() != mat2.getCol() || mat1.getRow() != mat2.getRow()){
        throw "Size of matrices are not the same";
    }
    Matrix m(mat1.getRow(), mat1.getCol());
    for(int i = 0; i < mat1.getRow(); i++){
        for(int j = 0; j < mat1.getCol(); j++){
            m.set_value(i,j, (mat1.get_value(i,j) - mat2.get_value(i,j)));
        }
    }
    return m;
}


Matrix& Matrix::operator*=(const Matrix& mat){
    if(this->getCol() != mat.getRow()){
        throw"Error";
    }
    Matrix m(this->getRow(), mat.getCol());
    double value;
    for(int i = 0; i < m.getRow(); ++i){
        for(int j = 0; j < m.getCol(); ++j){
            value = 0;
            for(int k = 0; k < getCol(); ++k){
                value += get_value(i,k) * mat.get_value(k,j);
            }
            m.set_value(i,j, value);
        }
    }
    *this = m;
    return *this;
}

Matrix operator*(const Matrix& mat1, const Matrix& mat2){

    Matrix m(mat1.getRow(), mat2.getCol());
    m = mat1;
    m *= mat2;
    return m;
}



