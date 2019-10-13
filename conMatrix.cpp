//
// Created by Alec on 2019-10-13.
//

#include <iomanip>
#include "conMatrix.hpp"
using namespace std;

conMatrix::conMatrix():Matrix(){

}
conMatrix::conMatrix(double *a, int n) : Matrix(a, n) {

}

conMatrix::conMatrix(const conMatrix &m) : Matrix(m) {

}

conMatrix::~conMatrix() {

}
std::ostream & operator << (std::ostream &os, const conMatrix &m){
    for (int r = 0; r<m.getRow(); ++r) {
        for (int c = 0; c<m.getRow(); ++c) {
            os << fixed << setprecision(0) << m.get_value(r, c) << " ";
        }
        os << "\n";
    }
    return os;
}