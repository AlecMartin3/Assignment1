//
// Created by Alec on 2019-10-13.
//

#ifndef ASSIGNMENT1_PAGERANK_HPP
#define ASSIGNMENT1_PAGERANK_HPP
#include <iostream>
#include "matrix.hpp"
#include "conMatrix.hpp"
using namespace std;

class PageRank {
private:
    int W;
    double *G;
public:
    PageRank();
    ~PageRank();
    conMatrix createG();
};


#endif //ASSIGNMENT1_PAGERANK_HPP
