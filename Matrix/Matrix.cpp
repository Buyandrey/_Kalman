# include "Matrix.h"

Matrix :: Matrix(const size_t n, const size_t m)
	: _n(n), _m(m) {
	_M.resize(_m);
	for (vector<double>& i : _M) { i.resize(_n); }
}

size_t  Matrix :: Get_n() const { return _n; }
size_t  Matrix :: Get_m() const { return _m; }

vector<vector<double>>  Matrix :: Get_Matrix() const { return _M; }
void Matrix::Set_Matrix(const vector<vector<double>>& data) { _M = data; }
void Matrix :: T(Matrix& M){}

void Matrix:: PrintMatrix() {
	for (size_t i = 0; i < _m; i++) {
		for (size_t j = 0; j < _n; j++)
			cout << setw(4) << setfill(' ') << _M.at(i).at(j);
		cout << endl;
	}
	cout << endl;

}

void Matrix:: operator=(const Matrix& rhs) {

	Set_Matrix(rhs.Get_Matrix());
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.Get_m() == rhs.Get_m() && lhs.Get_n() == rhs.Get_n()) {
		Matrix res(lhs.Get_n(), lhs.Get_m());

		strmatr t = lhs.Get_Matrix();
		for (size_t i = 0; i < lhs.Get_m(); i++) {
			for (size_t j = 0; j < lhs.Get_n(); j++) {
				t.at(i).at(j)=(lhs.Get_Matrix().at(i).at(j) + rhs.Get_Matrix().at(i).at(j));
			}
		}
		res.Set_Matrix(t);
		return(res);
	}
	else {
		throw invalid_argument("Matrix's size are not equal !!!");
	}
}
Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.Get_m() == rhs.Get_m() && lhs.Get_n() == rhs.Get_n()) {
		Matrix res(lhs.Get_n(), lhs.Get_m());

		strmatr t = lhs.Get_Matrix();
		for (size_t i = 0; i < lhs.Get_m(); i++) {
			for (size_t j = 0; j < lhs.Get_n(); j++) {
				t.at(i).at(j) = (lhs.Get_Matrix().at(i).at(j) - rhs.Get_Matrix().at(i).at(j));
			}
		}
		res.Set_Matrix(t);
		return(res);
	}
	else {
		throw invalid_argument("Matrix's size are not equal !!!");
	}
}
//Matrix operator*(const Matrix& lhs, const Matrix& rhs);

/*
  [ []    []    []    []  ] n=6 / m=4
	[]    []    []    []
	[]    []    []    []
	[]    []    []    []
	[]    []    []    []
	[]    []    []    []

*/