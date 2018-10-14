#include <iostream>
#include "matrix.hpp"
#include "pageRank.hpp"

int main() {


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
    //std::cout << importance;

    ranker.randomWalk(G, 0.85);

    return 0;
}