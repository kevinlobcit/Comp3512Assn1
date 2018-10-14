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
    matrix& markov(matrix, matrix&); //markov process
};


#endif //COMP3512ASSN1_PAGERANK_HPP
