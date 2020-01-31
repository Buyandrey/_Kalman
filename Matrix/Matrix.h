#pragma once
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <iostream>

/*
Создаётся математический объект "Матрица".
Матрица должна иметь размер n на m.
n может быть равно m. n и/или m не могут быть равны нулю.

	  [ []    []    []    []  ] n=6 / m=4
		[]    []    []    []
		[]    []    []    []
		[]    []    []    []
		[]    []    []    []
		[]    []    []    []

*/

using namespace std;
using strmatr = vector<vector<double>>;

class Matrix {

public:

	Matrix(const size_t n, const size_t m);
	Matrix(const strmatr& str);
	size_t Get_n()const;
	size_t Get_m()const;
	vector<double> Get_Column(const size_t& i);
	vector<double> Get_Str(const size_t& i);
	vector<vector<double>> Get_Matrix()const;
	void Set_Matrix(const vector<vector<double>>& data);
	void Insert(const double& v, const size_t& i, const size_t& j);
	void PrintMatrix();
	void operator=(const Matrix& rhs);

protected:
	
	vector<vector<double>> _M;
	const size_t _n;
	const size_t _m;

};

double ReturnSumOfMultiply(const vector<double>& a, const vector<double>& b);
Matrix operator*(const double& value, const Matrix& m);
Matrix operator*(const Matrix& m,   const double& value);

Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
ostream& operator << (ostream& os, const vector<double>& r);

Matrix operator*(Matrix& lhs, Matrix& rhs);

//template<typename V>
//Matrix operator*(const V& lhs, const Matrix& rhs);


//Matrix operator*(const Matrix& lhs, const Matrix& rhs);
