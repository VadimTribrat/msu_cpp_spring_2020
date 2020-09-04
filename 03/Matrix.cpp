#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
	int n, m, k;
	std::cout << "Введите количество строк и количество столбцов\n";
	std::cin >> n >> m;
	ptr = new int *[n];
	rows = n;
	columns = m;
	for(size_t i=0; i<rows; i++)
	{
		ptr[i] = new int[columns];
	}
	std::cout << "Введите значения матрицы\n";
	for(size_t i = 0; i<rows; i++)
	{
		for(size_t j = 0; j<columns; j++)
		{
			std::cin >> k;
			ptr[i][j] = k;
		}
	}
}
	
Matrix::~Matrix()
{
	for(size_t i = 0; i < rows; i++)
		delete[] ptr[i];
	delete[] ptr;
}
size_t Matrix::getColumns()
{
	return columns;
}

size_t Matrix::getRows()
{
	return rows;
}

Matrix::Proxy::Proxy(int * const p, int kol)
{
	row = p;
	col = kol;
}

int & Matrix::Proxy::operator [](int i)
{
	if ((i>=col) || (i<0))	
		throw std::out_of_range("");
	return row[i];
}

Matrix::Proxy::~Proxy()
{
}

void Matrix::print()
{
	for(size_t i = 0; i<rows; i++)
	{
		for(size_t j = 0; j<columns; j++)
			std::cout << ptr[i][j] << " ";
		std::cout << std::endl;
	}
}

Matrix::Proxy Matrix::operator [](int i)
{
	if ((i>=rows) || (i<0))	
		throw std::out_of_range("");
	Matrix::Proxy pr(ptr[i], columns);
	return pr;	
}

Matrix::Proxy::Proxy(const Proxy & dubl)
{
	row = dubl.row;
	col = dubl.col;
}
