//
// Created by Alec on 2019-10-13.
//

#include "PageRank.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

PageRank::PageRank() {
    int i = 0;
    double d_num = 0.0;
    ifstream file;
    file.open("connectivity.txt");
    while (file >> d_num) {
        i++;
    }
    W = i;
    file.close();

    array[W-1];
    int j = 0;

    file.open("connectivity.txt");
    while (file >> d_num) {
        array[j] = d_num;
        j++;
    }
    file.close();
}

PageRank::~PageRank(){

}

conMatrix PageRank::createG() {
    conMatrix g(array, W);
    return g;
}
Matrix PageRank::createS(const Matrix &g) {
    Matrix s(array, W);
    s = g;
    for (int i = 0; i < s.getCol(); ++i) {
        sum = 0;
        for (int j = 0; j < s.getRow(); ++j) {
            if (s.get_value(j, i) == 1)
                sum++;
        }
        if (sum != 0) {
            for (int k = 0; k < s.getRow(); ++k) {
                s.set_value(k, i, s.get_value(k, i) / sum);
            }
        }
    }
    return s;
}
Matrix PageRank::createSBlank(const Matrix &g) {
    Matrix s(array, W);
    s = g;
    for (int i = 0; i < s.getCol(); i++) {
        bool zeroCol = true;
        for (int j = 0; j < s.getRow(); j++) {
            if (s.get_value(j, i) != 0)
                zeroCol = false;
        }
        if (zeroCol) {
            for (int k = 0; k < s.getRow(); k++) {
                s.set_value(k, i, 1.0 / s.getRow());
            }
        }
    }
    return s;
}

Matrix PageRank::createQ() {
    Matrix q(array, W);
    for (int i = 0; i < q.getCol(); i++) {
        for (int j = 0; j < q.getRow(); j++) {
            q.set_value(i, j,  1.0 / q.getRow());
        }
    }
    return q;

}

Matrix PageRank::createR(const Matrix &s, const Matrix &q) {
    Matrix r1;
    Matrix r;
    r1 = s;
    for (int i = 0; i < r1.getCol(); i++) {
        for (int j = 0; j < r1.getRow(); j++) {
            r1.set_value(i, j, (r1.get_value(i, j)*0.85));
        }
    }
    Matrix r2;
    r2 = q;
    for (int i = 0; i < r2.getCol(); i++) {
        for (int j = 0; j < r2.getRow(); j++) {
            r2.set_value(i, j, (r2.get_value(i, j)*(1.0-0.85)));
        }
    }
    r = r1+r2;
    return r;
}

Matrix PageRank::createRank(const Matrix &m) {
Matrix rank(m.getRow(), 1);
    for (int i = 0; i < m.getRow(); i++) {
    rank.set_value(i, 0, 1.0);
    }
return rank;
}

Matrix PageRank::multiplyRank(const Matrix &rank, const Matrix &m) {
    Matrix result = m * rank;
    if(result!=rank) {
        result = multiplyRank(result, m);
    }
    return result;
}

Matrix PageRank:: divideRank(const Matrix &m){
    double total = 0;
    for (int i = 0; i < m.getRow(); i++) {
        total += m.get_value(i,0);
    }
    Matrix rank = m;
    for (int j = 0; j < rank.getRow(); j++) {
        rank.set_value(j, 0, (rank.get_value(j, 0) / total)*100.0);
    }
    return rank;
}

void PageRank::printResults(){
    conMatrix g = createG();
    cout << g << endl;
    Matrix s = createS(g);
    Matrix sb = createSBlank(s);
    Matrix q = createQ();
    Matrix r = createR(sb, q);
    Matrix rank = createRank(sb);
    Matrix result = multiplyRank(rank, r);
    Matrix ranked = divideRank(result);
    char l='A';
    for (int i = 0; i < ranked.getRow(); i++){
        cout << "Page " << static_cast<char>(l++) << ": "
             << fixed << setprecision(2) << ranked.get_value(i, 0) << "%" << endl;
    }
}