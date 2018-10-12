#include <iostream>
#include "matrix.hpp"

int main() {

    matrix box = matrix(3);
    box.set_value(2,2,10);

    matrix box2 = matrix(3);
    box2.set_value(1,2,4);
    box2.set_value(1,1,4);




    box += box2;



    std::cout << box;
    return 0;
}