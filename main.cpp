#include <iostream>
#include "matrix.hpp"
#include "pageRank.hpp"
#include <fstream>

int main() {
    //Setting values

    std::ifstream f;
    f.open("connectivity.txt");
    std::string line;
    if(f.is_open())
    {
        while(getline(f, line))
        {
            std::cout << line << '\n';
        }
        f.close();
    }
    else std::cout << "Unable to open file";



    int W = 4;
    matrix G = matrix(W);
    G.set_value(0,1,1);
    G.set_value(0,2,1);

    G.set_value(1,0,1);
    G.set_value(1,2,1);

    G.set_value(2,0,1);
    G.set_value(2,1,1);
    //std::cout << G;









    pageRank ranker = pageRank();
    matrix importance = ranker.getImportance(G, W);
    //std::cout << "Importance" << std::endl;
    //std::cout << importance;

    //std::cout << "Random walk" << std:: endl;
    matrix M = ranker.randomWalk(importance, 0.85, W);
    //std::cout<<M;

    //std::cout << "Markov" << std::endl;
    matrix rank = matrix(4,1);
    ranker.markov(M, rank, W);
    //std::cout<<rank;

    ranker.printPercent(rank, W);
    return 0;
}