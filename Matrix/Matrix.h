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
	Matrix();
	Matrix(const size_t n, const size_t m);

	size_t Get_n()const;
	size_t Get_m()const;

	void Set_n(const size_t& n);
	void Set_m(const size_t& m);

	vector<vector<double>> Get_Matrix()const;
	void Set_Matrix(const vector<vector<double>>& data);

	void T(Matrix& M);

	void PrintMatrix();

	void operator=(const Matrix& rhs);

private:


	vector<vector<double>> _M;
	const size_t _n;
	const size_t _m;

};

Matrix operator+(const Matrix& lhs, const Matrix& rhs);

//Matrix operator=(Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
//Matrix operator*(const Matrix& lhs, const Matrix& rhs);
