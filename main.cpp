#include <iostream>
#include "matrix.hpp"

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





    return 0;
}