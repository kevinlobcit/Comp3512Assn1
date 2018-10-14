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
    matrix getImportance(matrix, int); //Page importances and returns a matrix of it
    matrix randomWalk(matrix, double, int); //random walk calculation with a specific value of randomness
    void prepRank(matrix&, int); //Prepares the array for the ranking
    matrix& markov(matrix, matrix&, int); //markov process
    void printPercent(matrix, int) const; //print the percentage
};


#endif //COMP3512ASSN1_PAGERANK_HPP
