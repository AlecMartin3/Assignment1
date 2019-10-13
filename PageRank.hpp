//
// Created by Alec on 2019-10-13.
//

#ifndef ASSIGNMENT1_PAGERANK_HPP
#define ASSIGNMENT1_PAGERANK_HPP
#include <iostream>
#include "Matrix.hpp"
#include "conMatrix.hpp"
using namespace std;

class PageRank {
private:
    int W;
    double *array;
    int sum;
public:
    PageRank();
    ~PageRank();
    conMatrix createG();
    Matrix createS(const Matrix &g);
    Matrix createSBlank(const Matrix &g);
    Matrix createQ();
    Matrix createR(const Matrix &s, const Matrix &q);
    Matrix createRank(const Matrix &m);
    Matrix multiplyRank(const Matrix &rank, const Matrix &m);
    Matrix divideRank(const Matrix &m);
    void printResults();
};


#endif //ASSIGNMENT1_PAGERANK_HPP
