//
// Created by Alec on 2019-10-13.
//

#ifndef ASSIGNMENT1_CONMATRIX_HPP
#define ASSIGNMENT1_CONMATRIX_HPP

#include "Matrix.hpp"
/*
 * Makes a conMatrix that uses only 1s and 0s, is created from a file. Uses the Matrix class as a parent
 */
class conMatrix : public Matrix {
public:
    conMatrix();
    conMatrix(double a[], int n);
    virtual ~conMatrix();
    friend std::ostream & operator << (std::ostream &os, const conMatrix &m);

};

#endif //ASSIGNMENT1_CONMATRIX_HPP
