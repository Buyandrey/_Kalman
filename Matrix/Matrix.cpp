# include "Matrix.h"
using namespace std;

/*методы*/
Matrix :: Matrix(const strmatr& str)
								:_n(str.size()),
								_m(str.at(0).size()),
								_M(str){}
Matrix :: Matrix(const size_t n, const size_t m)
		: _n(n), _m(m) {
		_M.resize(_n);
	for (vector<double>& i : _M) { i.resize(_m); }
}
size_t Matrix :: Get_n() const { return _n; }
size_t Matrix :: Get_m() const { return _m; }
vector<double> Matrix :: Get_Str(const size_t& i) {
	if(i>_n) 
		throw invalid_argument("Can't cout this line, may be out of range !");
	else
		return(_M.at(i-1));
}
vector<double> Matrix :: Get_Column(const size_t& i) {
	if (i > _m) 
		throw invalid_argument("Can't cout this column, may be out of range !");

	vector<double> res;
	for (size_t it=0;it<_M.at(i).size();it++)
		res.push_back(_M.at(it).at(i));
	return(res);
}
vector<vector<double>> Matrix :: Get_Matrix() const { return _M; }
void Matrix :: Set_Matrix(const vector<vector<double>>& data) { _M = data; }
void Matrix :: PrintMatrix() {
	for (size_t i = 0; i < _n; i++) {
		for (size_t j = 0; j < _m; j++)
			cout << setw(4) << setfill(' ') << _M.at(i).at(j);
		cout << endl;
	}
	cout << endl;
}
void Matrix :: operator=(const Matrix& rhs) {

	Set_Matrix(rhs.Get_Matrix());
}
void Matrix :: Insert(const double& v, const size_t& i, const size_t& j) {
	if(i>_n || j>_m)
		throw invalid_argument("This vector and column can't be _*_, size's are not equal");

	_M.at(i).at(j) = v;
}

/**/

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.Get_m() == rhs.Get_m() && lhs.Get_n() == rhs.Get_n()) {
		Matrix res(lhs.Get_n(), lhs.Get_m());

		strmatr t = lhs.Get_Matrix();
		for (size_t i = 0; i < lhs.Get_n(); i++) {
			for (size_t j = 0; j < lhs.Get_m(); j++) {
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
		for (size_t i = 0; i < lhs.Get_n(); i++) {
			for (size_t j = 0; j < lhs.Get_m(); j++) {
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
Matrix operator*(const double& value, const Matrix& m) {

	Matrix r(m.Get_n(),m.Get_m());
	strmatr vv=m.Get_Matrix();
	for (size_t i = 0; i < m.Get_n(); i++) {
		for (size_t j = 0; j < m.Get_m(); j++) {
			vv.at(i).at(j) = vv.at(i).at(j)* (value);
		}
	}
	r.Set_Matrix(vv);
	return r;
}
Matrix operator*(const Matrix& m, const double& value) {

	Matrix r(m.Get_n(), m.Get_m());
	strmatr vv = m.Get_Matrix();
	for (size_t i = 0; i < m.Get_n(); i++) {
		for (size_t j = 0; j < m.Get_m(); j++) {
			vv.at(i).at(j) = vv.at(i).at(j) * (value);
		}
	}
	r.Set_Matrix(vv);
	return r;
}

double	ReturnSumOfMultiply(const vector<double>& a, const vector<double>& b) {
	if (!(a.size() - b.size())) {
		double res = 0;
		for (size_t ij = 0; ij < b.size(); ij++)
			res += a.at(ij) * b.at(ij);
		return res;
	}
	else
		throw invalid_argument("This vector and column can't be _*_, size's are not equal");

}

ostream&  operator << (ostream& os, const vector<double>& r) {
	os << "[ ";
	for (const double& i : r) {
		os << i << ' ';
	}
	return  os << ']';
}

Matrix operator*( Matrix& lhs,  Matrix& rhs) {
	if ( lhs.Get_m() == rhs.Get_n() ) {
		Matrix res(lhs.Get_n(),rhs.Get_m());

		double r;
		for (size_t i = 0; i < lhs.Get_n(); i++) {
			for (size_t j = 0; j < rhs.Get_m(); j++) {
				r = ReturnSumOfMultiply(rhs.Get_Column(j+1), lhs.Get_Str(i+1));
				res.Insert(r, i, j);
			}
		}
		return res;
	}
	else {
		throw invalid_argument("This matrix can't be _*_, size's are not equal ");
	}
}


/*
  [ []    []    []    []  ] n=6 / m=4
	[]    []    []    []
	[]    []    []    []
	[]    []    []    []
	[]    []    []    []
	[]    []    []    []

*/