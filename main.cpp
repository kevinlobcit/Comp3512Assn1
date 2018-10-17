#include <iostream>
#include "matrix.hpp"
#include "pageRank.hpp"
#include <fstream>
#include <vector>
#include <sstream>
#include <stdio.h>

int main() {
    //Inputting the array of hth
    std::vector<int> matrixVector;
    std::ifstream file;
    file.open("connectivity.txt"); //inside the debug folder

    int number = 0;
    while(file >> number)
    {
        matrixVector.push_back(number);
    }
    file.close();
    int W = (int)sqrt(matrixVector.size());

    matrix G = matrix(W);
    int counter = 0;
    int i = 0;
    int i2 = 0;
    while(counter < W*W)
    {
        if(counter%W == 0 && counter != 0)
        {

            i2++;
            i = 0;
        }
        G.set_value(i2,i,matrixVector.at(counter));
        i++;
        counter++;
    }
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