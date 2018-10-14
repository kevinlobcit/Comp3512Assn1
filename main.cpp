#include <iostream>
#include "matrix.hpp"
#include "pageRank.hpp"

int main() {
    //Setting values
    int W = 4;
    matrix G = matrix(W);
    G.set_value(0,1,1);
    G.set_value(0,2,1);

    G.set_value(1,0,1);
    G.set_value(1,2,1);

    G.set_value(2,0,1);
    G.set_value(2,1,1);
    std::cout << G;

    pageRank ranker = pageRank();
    matrix importance = ranker.getImportance(G, W);
    std::cout << "Importance" << std::endl;
    std::cout << importance;

    std::cout << "Random walk" << std:: endl;
    matrix M = ranker.randomWalk(importance, 0.85, W);
    std::cout<<M;

    std::cout << "Markov" << std::endl;
    matrix rank = matrix(4,1);
    rank.set_value(0,0,1);
    rank.set_value(1,0,1);
    rank.set_value(2,0,1);
    rank.set_value(3,0,1);

    std::cout<<M*rank;


    /*
    matrix a = matrix(2,3);
    a.set_value(0,0,2);
    a.set_value(0,1,2);
    a.set_value(0,2,2);
    a.set_value(1,0,2);
    a.set_value(1,1,2);
    a.set_value(1,2,2);

    matrix b = matrix(3,4);
    b.set_value(0,0,6);
    b.set_value(0,1,1);
    b.set_value(0,2,6);
    b.set_value(0,3,2);
    b.set_value(1,0,2);
    b.set_value(1,1,6);
    b.set_value(1,2,3);
    b.set_value(1,3,6);
    b.set_value(2,0,2);
    b.set_value(2,1,6);
    b.set_value(2,2,3);
    b.set_value(2,3,6);
/*
    std::cout << a;
    std::cout<<b;
*/
    //std::cout<<a*b;


    return 0;
}