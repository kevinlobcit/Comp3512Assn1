//
// Created by Owntrolf on 2018-10-11.
//
#include <vector>
#include <math.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <iomanip>

#ifndef COMP3512ASSN1_MATRIX_HPP
#define COMP3512ASSN1_MATRIX_HPP

//Making matrixes
class matrix {
private:
    std::vector<std::vector<double>> double2d;
public:
    matrix();
    matrix(int);
    matrix(int, int);
    matrix(double*, int);
    void filler(std::string, matrix&, int&); //Resizes matrix to fit a square string of numbers with designated file if possible because my array is backwards
    void set_value(int, int, double);
    double get_value(int, int) const;
    void clear();
    ~matrix();

    //Operator Overloads
    friend std::ostream& operator<<(std::ostream&, matrix);
    friend bool operator ==(matrix, matrix);
    friend bool operator !=(matrix, matrix);
    friend matrix& operator++(matrix&);
    friend matrix operator++(matrix&, int);
    friend matrix& operator--(matrix&);
    friend matrix operator--(matrix&, int);

    matrix& operator =(const matrix&);
    friend void swap(matrix*, matrix, int, int);

    friend matrix& operator+=(matrix&, matrix);
    friend matrix& operator+(matrix&, matrix);

    friend matrix& operator-=(matrix&, matrix);
    friend matrix& operator-(matrix&, matrix);

    friend matrix& operator*(matrix, matrix&);
    friend matrix& operator*=(matrix, matrix&);


};




#endif //COMP3512ASSN1_MATRIX_HPP
