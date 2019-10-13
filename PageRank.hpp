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
    ~PageRank() = default;
    conMatrix createG();
    Matrix createS(const Matrix &g);
    Matrix createSBlank(const Matrix &g);
    Matrix createQ();
    Matrix createM(const Matrix &s, const Matrix &q);
    Matrix createRank(const Matrix &m);
    Matrix multiplyRank(const Matrix &rank, const Matrix &m);
    Matrix divideRank(const Matrix &m);
    void printResults();
};


#endif //ASSIGNMENT1_PAGERANK_HPP
