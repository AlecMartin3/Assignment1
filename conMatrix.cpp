//
// Created by Alec on 2019-10-13.
//

#include "conMatrix.hpp"
using namespace std;

conMatrix::conMatrix():Matrix(){

}

conMatrix::conMatrix(int n) : Matrix(n) {

}

conMatrix::conMatrix(double *a, int n) : Matrix(a, n) {

}

conMatrix::conMatrix(const conMatrix &m) :Matrix(m) {

}

conMatrix::~conMatrix() {

}