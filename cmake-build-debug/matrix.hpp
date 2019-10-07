//
// Created by Alec on 2019-09-30.
//

#ifndef ASSIGNMENT1_MATRIX_HPP
#define ASSIGNMENT1_MATRIX_HPP

using namespace std;

class Matrix{

public:
    Matrix();
    Matrix(int col, int row);
    Matrix(int n);
    Matrix(double arr[]);
    void set_value(int col, int row, double newVal);
    double get_value(int col, int row) const;
    void clear();
    ~Matrix();
    int getRow() const;
    int getCol() const;



    friend ostream& operator<<(ostream& os, const Matrix& mat);
    friend bool operator==(const Matrix& mat1, const Matrix& mat2);
    friend bool operator!=(const Matrix& mat1, const Matrix& mat2);
    Matrix& operator++();
    Matrix& operator++(int);
    Matrix& operator--();
    Matrix& operator--(int);
    Matrix& operator=(const Matrix& mat);
    friend void mySwap(Matrix& mat1, Matrix mat2);
    friend Matrix& operator+(const Matrix& mat1, const Matrix& mat2);
    friend Matrix& operator-(const Matrix& mat1, const Matrix& mat2);


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
