//
// Created by Alec on 2019-10-13.
//

#ifndef ASSIGNMENT1_PAGERANK_HPP
#define ASSIGNMENT1_PAGERANK_HPP
#include <iostream>
#include "Matrix.hpp"
#include "conMatrix.hpp"
using namespace std;
/*
 * Google page rank algorithm class. An algorithm using matrices to determine the importance of each page on google
 * Uses the Matrix and conMatrix classes.
 */
class PageRank {
private:
    int W;
    double *array;
    int sum;
public:
    PageRank();
    ~PageRank();
    conMatrix G();
    Matrix S(const Matrix &g);
    Matrix S2(const Matrix &g);
    Matrix Q();
    Matrix M(const Matrix &s, const Matrix &q);
    Matrix Rank(const Matrix &m);
    Matrix multiply(const Matrix &rank, const Matrix &m);
    Matrix divide(const Matrix &m);
    void printResults();
};


#endif //ASSIGNMENT1_PAGERANK_HPP
