//
// Created by Alec on 2019-10-13.
//

#ifndef ASSIGNMENT1_CONMATRIX_HPP
#define ASSIGNMENT1_CONMATRIX_HPP

#include "Matrix.hpp"

class conMatrix : public Matrix {
public:
    conMatrix();
    conMatrix(int n);
    conMatrix(double a[], int n);
    conMatrix(const conMatrix&m);
    virtual ~conMatrix();
    friend std::ostream & operator << (std::ostream &out, const conMatrix &m);

};

#endif //ASSIGNMENT1_CONMATRIX_HPP
