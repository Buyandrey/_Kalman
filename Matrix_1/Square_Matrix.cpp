#include "Square_Matrix.h"
#include <iostream>

using namespace std;

MatrixException::MatrixException(int i)
{
	numError = i;
}
const wchar_t* MatrixException::Error() const
{
	static const wchar_t* arrayErrors[] =
	{
		/*  0  */	L"����������� ������.",
		/*  1  */	L"������������. ������� ������� � ��������������� ��������.",
		/*  2  */	L"�������� ������� �� ����������: ������������ ����� 0.",
		/*  3  */	L"���������� ���������� ����� ��� ������� ������� �������.",
		/*  4  */	L"�������� ����� ����������.",
		/*  5  */	L"������ ����� ������� �������.",
		/*  6  */	L"���������� �������� ������.",
		/*  7  */	L"������ ���� � ����� ������� ���.",
		/*  8  */	L"������ ������� ������ ���������� ����� ������ � ���� ������ ����.",
		/*  9  */	L"���������� ��������� �������� ��������. ��������� �������� ��������.",
		/*  10 */	L"���������� ������� ���� ��� ������.",
		/*  11 */	L"���������� ������� ���� ��� ������.",
		/*  12 */	L"���������� ����� � ����� ������ ������������.",
		/*  13 */	L"��� ������ � ����� �������.",
		/*  14 */	L"��� ������� � ����� �������."
	};

	if (numError >= 0 && numError <= 15) {
		return arrayErrors[numError];
	}
	else {
		return 0;
	}
}
SquareMatrix::SquareMatrix(int inSize)
{
	try {
		if (inSize <= 0) {
			throw MatrixException(8);
		}
		size = inSize;
		M = (double**) new double[size];
		for (int i = 0; i < size; i++) {
			M[i] = (double*) new double[size];
			for (int j = 0; j < size; j++) {
				M[i][j] = 0;
			}
		}
	}
	catch (bad_alloc) {
		throw MatrixException(6);
	}
}
double& SquareMatrix::operator()(int row, int col) const
{
	if (row >= size || col >= size) {
		throw MatrixException(1);
	}
	return (double&)M[row][col];
}
SquareMatrix SquareMatrix::operator*(const double& f)
{
	if (f == 0) {
		throw MatrixException(4);
	}
	for (int i = 0, j; i < size; i++) {
		for (j = 0; j < size; j++) {
			(*this)(i, j) *= f;
		}
	}
	return *this;
}
SquareMatrix SquareMatrix::operator!()
{
	SquareMatrix newMatrix(size);
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			newMatrix(j, i) = (*this)(i, j);
		}
	}
	return newMatrix;
}
SquareMatrix& SquareMatrix::operator=(const double& f)
{
	if (f == 0) {
		throw MatrixException(4);
	}
	for (int i = 0, j; i < size; i++) {
		for (j = 0; j < size; j++) {
			if (i == j) {
				(*this)(i, j) = f;
			}
			else {
				(*this)(i, j) = 0;
			}
		}
	}
	return *this;
}
double SquareMatrix::Determinant() const {
	double determ = 0;
	if (size == 1) {
		return (*this)(0, 0);
	}
	for (int i = 0; i < size; i++) {
		double a = (*this)(0, i) * (i % 2 ? -1 : 1);
		determ += a * this->PreMinor(0, i).Determinant();
	}
	return determ;
}
SquareMatrix SquareMatrix::Allied() {
	if ((size - 1) <= 0) {
		throw MatrixException(3);
	}
	SquareMatrix newMatrix(size);
	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			newMatrix(i, j) = this->PreMinor(i, j).Determinant() * ((i + j) % 2 ? -1 : 1);
		}
	}
	return newMatrix;
}
SquareMatrix SquareMatrix::PreMinor(int row, int col) const
{
	SquareMatrix newMatrix(size - 1);
	int i, j, in, jn;

	for (i = 0, in = 0; i < size; i++) {
		if (i != row) {
			for (j = 0, jn = 0; j < size; j++) {
				if (j != col) {
					newMatrix(in, jn++) = (*this)(i, j);
				}
			}
			in++;
		}
	}
	return newMatrix;
}
void SquareMatrix::Print()
{
	int i, j;
	//for (i=0; i<size; i++) {
	//		cout << " ---------------";
	//}
	//cout << endl;
	cout.precision(3);
	cout.setf(ios::showpoint | ios::fixed | ios::left);
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			//cout << "|" << " [" << i+1 << "," << j+1 << "]" << "\t" << (*this).M[i][j] << "\t";
			cout << "[" << i + 1 << "," << j + 1 << "]" << " ";
			cout.width(12);
			cout << (*this).M[i][j];
		}
		//cout << "|" << endl;
		//for (j=0;j<size;j++) {
		//	cout << " ---------------";
		//}
		cout << endl;
	}
}