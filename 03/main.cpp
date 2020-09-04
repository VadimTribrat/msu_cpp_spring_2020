#include "Matrix.h"
#include <iostream>
#include <assert.h>

using namespace std;

int main()
{
	Matrix m;	const size_t rows = 1, columns = 2;
	(m.getRows() == rows);
	assert(m.getColumns() == columns);
	m.print();
	m[0][0] = 15;
	cout << endl;
	m.print();
	return 0;
}
