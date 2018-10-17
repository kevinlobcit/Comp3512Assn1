#include <iostream>
#include "matrix.hpp"
#include "pageRank.hpp"
#include <fstream>
#include <vector>
#include <sstream>
#include <stdio.h>

int main() {
    //Inputting the array of hth
    matrix G;
    int W = -1;
    G.filler("connectivity.txt", G, W);
    std::cout<<G;
    pageRank ranker = pageRank();

    matrix importance = ranker.getImportance(G, W);
    std::cout << "Importance\n" << importance << std::endl;

    matrix M = ranker.randomWalk(importance, 0.85, W);
    std::cout<<"randomwalk\n" << M <<std::endl;

    matrix rank = matrix(W,1);
    ranker.markov(M, rank, W, 10000);

    ranker.printPercent(rank, W);

    return 0;
}