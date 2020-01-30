#include <iostream>
#include "Matrix.h"

using namespace std;
using strmatr = vector<vector<double>>;
int main()
{
    Matrix m1(2, 4);
    strmatr m1_str= { 
    {1.0 , 2.0},
    {2.0 , 3.0},
    {3.0 , 4.0},
    {4.0 , 5.0}
    };

    Matrix m2(2, 4);
    strmatr m2_str = {
    {9.0 , 8.0},
    {8.0 , 7.0},
    {7.0 , 6.0},
    {6.0 , 5.0}
    };
   Matrix m3(2, 4);

    m1.Set_Matrix(m1_str);
    m1.PrintMatrix();
    m2.Set_Matrix(m2_str);
    m2.PrintMatrix();
    m3 = m2+m1;
    m3.PrintMatrix();
    m3 =m3-m3;
    m3.PrintMatrix();



    return 0;
}
