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
    
}
