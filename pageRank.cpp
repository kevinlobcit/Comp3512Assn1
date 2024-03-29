//
// Created by Owntrolf on 2018-10-14.
//

#include "pageRank.hpp"
#include <iomanip>


pageRank::pageRank()
{

}

//Sorry not the recursive version
matrix pageRank::getImportance(matrix pageMatrix, int size)
{
    for(int i2 = 0; i2 < size; i2++)
    {
        double sum = 0;
        for(int i = 0; i < size; i++)
        {
            if(pageMatrix.get_value(i,i2) == 1)
                sum++;
        }
        for(int i = 0; i < size; i++)
        {
            if(sum != 0)
                pageMatrix.set_value(i,i2,pageMatrix.get_value(i,i2)/sum);
            else
                pageMatrix.set_value(i,i2,0);
        }
    }
    for(int i2 = 0; i2 < size; i2++)
    {
        int allZero = 0;
        for(int i = 0; i < size && allZero != 1; i++) {
            if (pageMatrix.get_value(i, i2) != 0)
            {
                //std::cout << pageMatrix.get_value(i, i2);
                allZero = 1;
            }
        }
        if(allZero == 0)
            for(int i = 0; i < size; i++)
            {
                pageMatrix.set_value(i,i2,1.0/size);
            }

    }
    return pageMatrix;
}


matrix pageRank::randomWalk(matrix S, double p, int n)
{
    double q = 1.0 - p;
    matrix Q = matrix(n);
    for(int i = 0; i < n; i++)
        for(int i2 = 0; i2 < n; i2++)
        {
            S.set_value(i,i2,S.get_value(i,i2)*p); // M * p
            Q.set_value(i,i2,1.0/n * q);    // Q*q
        }
    S+=Q;
    return S;
}

void pageRank::prepRank(matrix& rank, int W)
{
    for(int i = 0; i < W; i++)
    {
        rank.set_value(i,0,1);
    }
}

//Is the markov process and takes a certain threshhold just in case so it doesnt infinitely loop
matrix& pageRank::markov(matrix M, matrix& rank, int W, int threshhold)
{
    prepRank(rank, W);
    bool markDone = 0;
    int threshCounter = 0;
    matrix previous = rank;
    while(markDone == 0 && threshCounter <= threshhold)
    {
        threshCounter++;
        rank = M*rank;
        if(rank == previous)
            markDone = 1;
        previous = rank;
        //std::cout<<rank <<std::endl;

    }
    //std::cout<<rank;
    return rank;
}

//Prince the percentage rate of each page
void pageRank::printPercent(matrix rank, int W) const
{
    for(int i = 0; i < W; i++)
    {
        std::cout<< "Page " << i+1 << ": " << std::setprecision(2) << std::fixed << rank.get_value(i,0)/W*100 << "%" << std::endl;
    }
}

