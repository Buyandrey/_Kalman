#pragma once
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <utility>

using namespace std;
using strmatr = vector<vector<double>>;

void RESIZEvv(vector<vector<double>>& vv, const size_t& m1, const size_t& n2);

class matrix {
public:
	matrix(const strmatr& str);
	matrix();

	double Get_Element(const size_t& i, const size_t& j)const;
	pair<size_t, size_t> Get_MxN() const;
	void PrintMatrix();
	double Determinant() const;

	matrix PreMinor(const size_t& row, const size_t& col) const;
	matrix Inverted(const double& D) const;

	friend matrix operator*(const matrix& m, const double& value);
	friend matrix operator*(const double& value, const matrix& m);
	friend matrix operator*(const matrix& lhs, const matrix& rhs);
	friend matrix operator/(const matrix& lhs, const matrix& rhs);
	friend matrix operator+(const matrix& lhs, const matrix& rhs);
	friend matrix operator-(const matrix& lhs, const matrix& rhs);
	friend matrix Transponierte(const matrix& M);
private:

	vector<double> Get_Line(const size_t& i)const;
	vector<double> Get_Column(const size_t& i)const;
	double det4() const;
	strmatr _M;
};

ostream& operator << (ostream& os, const vector<double>& r);
ostream& operator << (ostream& os, const strmatr& r);
matrix operator*(const double& value, const matrix& M);
matrix operator*(const matrix& M, const double& value);
matrix operator*(const matrix& lhs, const matrix& rhs);
matrix operator/(const matrix& lhs, const matrix& rhs);
matrix operator+(const matrix& lhs, const matrix& rhs);
matrix operator-(const matrix& lhs, const matrix& rhs);
matrix Transponierte(const matrix& M);