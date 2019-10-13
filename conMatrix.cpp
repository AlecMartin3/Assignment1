//
// Created by Alec on 2019-10-13.
//


#include <iomanip>
#include "conMatrix.hpp"
using namespace std;
//Overriding Matrix()
conMatrix::conMatrix():Matrix(){

}
//Overriding Matrix(row, col)
conMatrix::conMatrix(double *a, int n) : Matrix(a, n) {

}
//Overriding copy matrix
conMatrix::conMatrix(const conMatrix &m) : Matrix(m) {

}
//Overriding Destructor matrix
conMatrix::~conMatrix() {

}
//Overriding << operator from matrix. Make it have a different precision level. Make it output 1 or 0 not 1.00 or 0.00
std::ostream & operator << (std::ostream &os, const conMatrix &m){
    for (int r = 0; r<m.getRow(); ++r) {
        for (int c = 0; c<m.getRow(); ++c) {
            os << fixed << setprecision(0) << m.get_value(r, c) << " ";
        }
        os << "\n";
    }
    return os;
}