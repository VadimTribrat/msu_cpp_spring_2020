#pragma once
#include <string>

class Matrix
{
	private:
	int * * ptr;
	size_t rows, columns;
	public:
	class Proxy
	{
		private:
		int * row, col;
		public:
		Proxy(int * const, int);
		int & operator[](int i);
		~Proxy();
		Proxy(const Proxy &);
	};
	Matrix();
	~Matrix();
	Proxy operator [](int);
	void print();
	size_t getRows();
	size_t getColumns();
};
