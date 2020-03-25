#include "mylib.h"
#include <cstdlib>
#include <iostream>

Matrix::Matrix(int row, int column)
{
	if ((row<0) || (column <0))
		throw 1;
	rows = row;
	columns = column;
	mat = (int * *) malloc(rows*sizeof(int *));
	for (int i =0; i<rows; i++)
		mat[i] = (int *) malloc(columns*sizeof(int));
	for (int i =0; i<rows; i++)
		for (int j=0; j<columns; j++)
			mat[i][j] = i+j;
}
Matrix::~Matrix()
{
	for(int i =0; i< rows; i++)
		free(mat[i]);
	free(mat);
}
Matrix::Str  Matrix::operator[](int i)
{
	if ((i <1) || (i> rows))
		throw std::out_of_range("");
	Str r(mat[i-1], columns);
	return r;
}
Matrix::Str::Str(int * p, int t)
{
	s = p;
	columns = t;
}
int &  Matrix::Str::operator[](int i)
{
	if ((i<1) || (i>columns))
		throw std::out_of_range("");
	return s[i-1];
}
Matrix::Str::Str(const Str& str)
{
	s = str.s;
	columns = str.columns;
}
int Matrix::getRows()
{
	return rows;
}
int Matrix::getColumns()
{
	return Matrix::columns;
}
int Matrix::operator==(const Matrix temp)
{
	int flag = 1;
	if ((rows != temp.rows) || (columns != temp.columns))
		return 0;
	for (int i=0; i< rows; i++)
		for (int j=0; j< columns; j++)
			if (mat[i][j] != temp.mat[i][j])
				flag = 0;
	return flag;
}
int Matrix::operator !=(const Matrix temp)
{
	return !(*this == temp);
}
void Matrix::operator *=(int t)
{
	for (int i =0; i<rows; i++)
		for (int j= 0 ; j<columns; j++)
			mat[i][j] *= t;
}
