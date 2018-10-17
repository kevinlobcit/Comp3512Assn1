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
        throw "Out of range exception";
        //throw exception
    }
    double2d[r][c] = value;
}

//8 2 param getter
double matrix::get_value(int r, int c) const
{
    if(r < 0 || c < 0 || r > double2d.size() || c > double2d[0].size())
    {
        throw "Out of range exception";
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

//10
matrix::~matrix()
{
    for(int i = 0; i < double2d.size(); i++)
    {
        double2d[i].clear();
    }
    double2d.clear();
}

//11
std::ostream& operator<<(std::ostream& os, matrix inMatrix)
{
    //os << "hi";
    std::vector<std::vector<double>> double2d = inMatrix.double2d;

    for(int i = 0; i < double2d.size(); i++)
    {
        for (int i2 = 0; i2 < double2d[i].size(); i2++)
        {
            os << std::setw(8) <<double2d[i][i2] << " ";
        }
        os << std::endl;
    }
    return os;
}

bool operator==(matrix matrix1, matrix matrix2)
{
    if(matrix1.double2d.size() != matrix2.double2d.size())
        return false;
    if(matrix1.double2d[0].size() != matrix2.double2d[0].size())
        return false;
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[0].size(); i2++)
        {
            if(matrix1.double2d[i][i2]!=matrix2.double2d[i][i2])
            {
                return false;
            }
        }
    }

    return true;
}

bool operator!=(matrix matrix1, matrix matrix2)
{
    return !(matrix1==matrix2);
}

//pre increment ++
matrix& operator++(matrix& matrix1)
{
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] += 1;
        }
    }

    return matrix1;
}

//Post increment ++
matrix operator++(matrix& matrix1, int)
{
    matrix temp(matrix1);
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] += 1;
        }
    }
    return temp;
}

//pre increment --
matrix& operator--(matrix& matrix1)
{
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] -= 1;
        }
    }

    return matrix1;
}

//Post increment --
matrix operator--(matrix& matrix1, int)
{
    matrix temp(matrix1);
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] -= 1;
        }
    }
    return temp;
}

//= operator overload
matrix& matrix::operator=(const matrix& matrix2)
{
    swap(this, matrix2, this->double2d.size(), this->double2d[0].size());
}

//swap assist for = ovperator overload
void swap(matrix* matrix1, matrix matrix2, int sizex, int sizey)
{
    for(int i = 0; i < sizex; i++)
    {
        for(int i2 = 0; i2 < sizey; i2++)
        {
            matrix1->set_value(i,i2, matrix2.get_value(i,i2));
        }
    }
}

//+ operator overload
matrix& operator+=(matrix& matrix1, matrix matrix2)
{

    if(matrix1.double2d.size() != matrix2.double2d.size())
        throw "Array size not matching";
    if(matrix1.double2d[0].size() != matrix2.double2d[0].size())
        throw "Array size not matching";
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] += matrix2.double2d[i][i2];
        }
    }
    return matrix1;
}

matrix& operator+(matrix& matrix1, matrix matrix2)
{

    if(matrix1.double2d.size() != matrix2.double2d.size())
        throw "Array size not matching";
    if(matrix1.double2d[0].size() != matrix2.double2d[0].size())
        throw "Array size not matching";
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] += matrix2.double2d[i][i2];
        }
    }
    return matrix1;
}

//- operator overloading
matrix& operator-=(matrix& matrix1, matrix matrix2)
{

    if(matrix1.double2d.size() != matrix2.double2d.size())
        throw "Array size not matching";
    if(matrix1.double2d[0].size() != matrix2.double2d[0].size())
        throw "Array size not matching";
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] -= matrix2.double2d[i][i2];
        }
    }
    return matrix1;
}

matrix& operator-(matrix& matrix1, matrix matrix2)
{

    if(matrix1.double2d.size() != matrix2.double2d.size())
        throw "Array size not matching";
    if(matrix1.double2d[0].size() != matrix2.double2d[0].size())
        throw "Array size not matching";
    for(int i = 0; i < matrix1.double2d.size(); i++)
    {
        for(int i2 = 0; i2 < matrix1.double2d[i].size(); i2++)
        {
            matrix1.double2d[i][i2] -= matrix2.double2d[i][i2];
        }
    }
    return matrix1;
}


//* operator overloading
matrix& operator*(matrix A, matrix &B)
{

    if(A.double2d[0].size() != B.double2d.size())
    {
        std::cout << "Does not match";
        throw "Array size not matching";
    }



    int a = A.double2d.size(); //n is matrix 1's y
    int b = A.double2d[0].size(); //n is matrix 1's x
    int c = B.double2d.size(); //p is matrix 2's y
    int d = B.double2d[0].size(); //m is matrix 2's x

    //std::cout << A;
    //std::cout << B;
    //m is  b or c
    //n = 3 a
    //p =4 d


    //std::cout << "values" << std::endl; //array size is n1*p ->>> p*n1 in my array

    matrix newMatrix = matrix(a, d);
    //Multiplying matrix
    for(int i = 0; i < a; i++)
    {
        for(int j = 0; j < d; j++)
        {
            double sum = 0;
            for(int k = 0; k < b; k++)
            {
                sum+=A.get_value(i,k) * B.get_value(k,j);
            }
            newMatrix.set_value(i,j,sum);
        }
    }

    B.double2d.resize(a);
    for(int i = 0; i<a; i++)
    {
        B.double2d[i].resize(d);
    }
    B = newMatrix;

    return B;
}

matrix& operator*=(matrix A, matrix &B)
{


    return A*B;
}
