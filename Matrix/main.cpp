#include <iostream>
#include "Matrix.h"



int main()
{
    try {
        using namespace std;
        using strmatr = vector<vector<double>>;
        // создание матрицы
        {
            strmatr data = {
                {1, 2, 3, 4},
                {9, 8, 7, 6},
                {1, 0, 1, 0},
                {2, 1, 2, 1},
                {8, 7, 7, 8}
            };
            strmatr data1 = {
                {1, 2},
                {3, 4}
            };
            Matrix m1(data);
            Matrix m2({
                {3, 0, 2, 1},
                {3, 0, 2, 1},
                {3, 0, 2, 1},
                {3, 0, 2, 1},
                {3, 0, 2, 1}
                });
            Matrix m3(2, 2); m3.Set_Matrix(data1);
            //m1.printmatrix();
            //m2.printmatrix();
            //m3.printmatrix();
        }
        // арифметические операции
        { //сложение, умножение, 
            /*strmatr data1 = {
                {1, 2, 3},
                {9, 8, 7},
                {1, 0, 1}
            };
            strmatr data2 = {
                {0, 1, -1},
                {0, 1, -1},
                {0, 1, -1}
            };
            Matrix m1(data1), m2(data2), m3(3, 3);
            m3 = m1 + m2;
            cout << " + \n";
            m3.PrintMatrix();
            cout << " *2 \n";
            m3 = m3 * 2;
            m3.PrintMatrix();
            cout << " *0.5 \n";
            m3 = m3 * 0.5;
            m3.PrintMatrix();
            cout << m1.Get_Column(3)<<endl<< m1.Get_Str(2)<<endl;*/

            Matrix m4({
                {3, 0, 2, 1},
                {3, 0, 2, 1},
                {3, 0, 2, 1},
                {3, 0, 2, 1},
                });
            Matrix m5({
                {-1, 0, 2, 1}
            });
            Matrix res(1, 4);
            res= m5* m4;
            res.PrintMatrix();
        }


        return 0;
    }
    catch (exception & e) {
        cout << e.what()<<endl;
        return 1;
    }
}
