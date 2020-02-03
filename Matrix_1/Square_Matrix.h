#pragma once
class MatrixException
{
private:
	int numError;
public:
	MatrixException(int i);
	const wchar_t* Error() const;
};
class SquareMatrix
{
public:

	double** M;
	int size;

	SquareMatrix(int inSize);

	double& operator	()	(int row, int col) const;
	SquareMatrix	operator	*	(const double& f);
	SquareMatrix	operator	!	();
	SquareMatrix& operator	=	(const double&);

	double Determinant() const;
	SquareMatrix Allied();
	SquareMatrix PreMinor(int row, int col) const;
	void Print();
};