#include <cstdlib>
#include <iostream>
#include <cstddef>
#include "mylib.h"

Matrix::Matrix(size_t row, size_t column): rows(row), columns(column)
{
	mat = (int * *) malloc(rows*sizeof(int *));
	if (mat == nullptr)
		throw std::invalid_argument("");
	for (size_t i =0; i<rows; i++)
	{
		mat[i] = (int *) malloc(columns*sizeof(int));
		if (mat[i] == nullptr)
		{
			free(mat);
			for (size_t j=0; j<i; j++)
				free(mat[j]);
			throw std::invalid_argument("");
		}
	}
	for (size_t i =0; i<rows; i++)
		for (size_t j=0; j<columns; j++)
			mat[i][j] = i+j;
}
Matrix::~Matrix()
{
	for(size_t i =0; i< rows; i++)
		free(mat[i]);
	free(mat);
}
Matrix::Str  Matrix::operator[](size_t i)
{
	if ((i <0) || (i> rows-1))
		throw std::out_of_range("");
	Str r(mat[i], columns);
	return r;
}
Matrix::Str::Str(int * p, size_t t)
{
	s = p;
	columns = t;
}
int &  Matrix::Str::operator[](size_t i)
{
	if ((i<0) || (i>columns-1))
		throw std::out_of_range("");
	return s[i];
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
int Matrix::operator==(const Matrix & temp)
{
	if ((rows != temp.rows) || (columns != temp.columns))
		return 0;
	for (size_t i=0; i< rows; i++)
		for (size_t j=0; j< columns; j++)
			if (mat[i][j] != temp.mat[i][j])
				return 0;
	return 1;
}
int Matrix::operator !=(const Matrix & temp)
{
	return !(*this == temp);
}
Matrix & Matrix::operator *=(int t)
{
	for (size_t i =0; i<rows; i++)
		for (size_t j= 0 ; j<columns; j++)
			mat[i][j] *= t;
	return *this;
}
