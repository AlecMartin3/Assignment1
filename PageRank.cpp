//
// Created by Alec on 2019-10-13.
//

#include "PageRank.hpp"
#include <iostream>

PageRank::PageRank() {

}

PageRank::~PageRank(){

}

conMatrix PageRank::createG() {
    conMatrix g(G, W);
    return g;
}