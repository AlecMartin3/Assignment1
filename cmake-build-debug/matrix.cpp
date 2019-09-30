//
// Created by Alec on 2019-09-30.
//
#include <iostream>
#include <sstream>
#include "matrix.hpp"

Matrix:: Matrix(){
    Matrix(1,1);
};
Matrix:: Matrix(double col, double row){
    if( col <= 0  || row <= 0 ) {
        throw "row/col is zero or negative";
    }
    allocateArr();
    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
        {
            a[i][j] = 0;
        }
    }
};