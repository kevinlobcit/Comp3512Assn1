//
// Created by Owntrolf on 2018-10-14.
//

#ifndef COMP3512ASSN1_PAGERANK_HPP
#define COMP3512ASSN1_PAGERANK_HPP

#include "matrix.hpp"

//Google pagerank simulations
class pageRank {
public:
    pageRank();
    matrix getImportance(matrix, int); //Page importances
    matrix randomWalk(matrix, double, int); //random walk
    void prepRank(matrix&, int);
    matrix& markov(matrix, matrix&, int); //markov process
    void printPercent(matrix, int); //print the percentage
};


#endif //COMP3512ASSN1_PAGERANK_HPP
