//

// Created by Owntrolf on 2018-10-11.
//

#include "matrix.hpp"

//3 Default constructor for 1x1 matrix at 0
matrix::matrix()
{
    double2d.resize(1);
    double2d[0].resize(1);
    double2d[0][0] = 0;
}

//4 for n x n matrix at 0
matrix::matrix(int n)
{
    double2d.resize(n);
    for(int i = 0; i < n; i++)
    {
        double2d[i].resize(n);

        //set to 0.0
        for(int i2 = 0; i2 < n; i2++)
        {
            double2d[i][i2] = 0.0;
        }
    }
}

//5 2 integers for r x c size matrix
matrix::matrix(int r, int c)
{
    double2d.resize(r);
    for(int i = 0; i < r; i++)
    {
        double2d[i].resize(c);
        for(int i2 = 0; i2 < c; i2++)
        {
            double2d[i][i2] = 0.0;
        }
    }
}

//6 array of double and the size of array
matrix::matrix(double* inArr, int size)
{
    int squrt = sqrt(size);
    if(squrt*squrt == size)
    {
        int counter = 0;
        double2d.resize(squrt);
        for(int i = 0; i < squrt; i++)
        {
            double2d[i].resize(squrt);
            for(int i2 = 0; i2 < squrt; i2++)
            {
                double2d[i][i2] = inArr[counter];
                counter++;
            }
        }
    }
}

//7 3 param mutator
void matrix::set_value(int r, int c, double value)
{
    if(r < 0 || c < 0 || r > double2d.size() || c > double2d[0].size())
    {
        //throw exception
    }
    double2d[r][c] = value;
}

//8 2 param getter
double matrix::get_value(int r, int c)
{
    if(r < 0 || c < 0 || r > double2d.size() || c > double2d[0].size())
    {
        //throw exception
    }
    return double2d[r][c];
}

//9 clear function
void matrix::clear()
{
    for(int i = 0; i < double2d.size(); i++)
    {
        for(int i2 = 0; i2 < double2d[0].size(); i2++)
        {
            double2d[i][i2] = 0.0;
        }
    }
}

matrix::~matrix()
{
    for(int i = 0; i < double2d.size(); i++)
    {
        double2d[i].clear();
    }
    double2d.clear();
}



