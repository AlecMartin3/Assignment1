//
// Created by Alec on 2019-10-13.
//

#include "PageRank.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>
//Default constructor. Reads the numbers from the file into d_num then makes an array where the values
//are equal to d_num
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
//Destructor for PageRank
PageRank::~PageRank(){

}
//Creates the array that is from the file
conMatrix PageRank::createG() {
    conMatrix g(array, W);
    return g;
}
//Creates the "importance". for every column where there is at least one 1 divide all the values by the number of 1s
//else leave it blank
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
//Creates the probability. For every column where there are no 1s set the values to be 1 divided by number of rows
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
//A new matrix where every element is 1/n(n = numbers of rows)
Matrix PageRank::createQ() {
    Matrix q(array, W);
    for (int i = 0; i < q.getCol(); i++) {
        for (int j = 0; j < q.getRow(); j++) {
            q.set_value(i, j,  1.0 / q.getRow());
        }
    }
    return q;

}
//The random walk. Where r = (0.85 + S + (1 - 0.85) * Q).
//Creates two matrices. One for 0,85 and one for 1 - 0.85
Matrix PageRank::createM(const Matrix &s, const Matrix &q) {
    Matrix m1;
    Matrix m;
    m1 = s;
    for (int i = 0; i < m1.getCol(); i++) {
        for (int j = 0; j < m1.getRow(); j++) {
            m1.set_value(i, j, (m1.get_value(i, j)*0.85));
        }
    }
    Matrix m2;
    m2 = q;
    for (int i = 0; i < m2.getCol(); i++) {
        for (int j = 0; j < m2.getRow(); j++) {
            m2.set_value(i, j, (m2.get_value(i, j)*(1.0-0.85)));
        }
    }
    m = m1+m2;
    return m;
}
//Creates a matrix of row x 1, where every value is 1
Matrix PageRank::createRank(const Matrix &m) {
Matrix rank(m.getRow(), 1);
    for (int i = 0; i < m.getRow(); i++) {
    rank.set_value(i, 0, 1.0);
    }
return rank;
}
//Multiply the M matrix by the rank. Keeps ding this till the rank stops changing
Matrix PageRank::multiplyRank(const Matrix &rank, const Matrix &m) {
    Matrix result = m * rank;
    if(result!=rank) {
        result = multiplyRank(result, m);
    }
    return result;
}
//Divides each element in the rank by total of the values. And sets them to be in percentages
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
//Creates all the matrices and combines them together then prints them out.
void PageRank::printResults(){
    Matrix g = createG();
    cout << g << endl;
    Matrix s = createS(g);
    Matrix sb = createSBlank(s);
    Matrix q = createQ();
    Matrix m = createM(sb, q);
    Matrix rank = createRank(sb);
    Matrix result = multiplyRank(rank, m);
    Matrix ranked = divideRank(result);
    char l='A';
    for (int i = 0; i < ranked.getRow(); i++){
        cout << "Page " << static_cast<char>(l++) << ": "
             << fixed << setprecision(2) << ranked.get_value(i, 0) << "%" << endl;
    }
}