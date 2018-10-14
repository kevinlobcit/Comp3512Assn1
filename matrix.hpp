//
// Created by Owntrolf on 2018-10-11.
//
#include <vector>
#include <math.h>
#include <iostream>

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
    void set_value(int, int, double);
    double get_value(int, int);
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
