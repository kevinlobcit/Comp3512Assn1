//
// Created by Owntrolf on 2018-10-11.
//
#include <vector>
#include <math.h>

#ifndef COMP3512ASSN1_MATRIX_HPP
#define COMP3512ASSN1_MATRIX_HPP


class matrix {

    std::vector<std::vector<double>> double2d;
    matrix();
    matrix(int);
    matrix(int, int);
    matrix(double*, int);
};


#endif //COMP3512ASSN1_MATRIX_HPP