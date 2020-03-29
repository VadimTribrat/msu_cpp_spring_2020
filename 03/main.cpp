#include <iostream>
#include "mylib.h"
#include <cstring>

using namespace std;

int main(int argc, char * * argv)
{
	cout << "\n\n";
	int * var = (int *) malloc (5*sizeof(int));
	for (int i =1; i<argc; i++)
		var[i-1] = atoi(argv[i]);
	try{
	Matrix mat(var[0], var[1]);
	for (int i=0; i<mat.getRows();i++)
	{
		for (int j=0; j<mat.getColumns(); j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << "\nRows: " << mat.getRows() << endl;
	cout << "Columns: "<< mat.getColumns()<< endl;
	cout << "Element mat["<< var[2] << "]["<< var[3]<<"] - ";
	cout << mat[var[2]][var[3]]<< endl;
	cout << "Multiply matrix by a "<< var[4]<< endl;
	mat *= var[4];
	for (int i=0; i<mat.getRows();i++)
	{
		for (int j=0; j<mat.getColumns(); j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	int b = mat == Matrix(var[0], var[1]);
	cout << "Compare matrices "<< b << "\n";
	}
	catch(std:: out_of_range s)
	{
		cout << "\nOut_of_range\n";
	}
	catch(std::invalid_argument a)
	{
		cout << "\n Invalid\n";
	}
	free(var);
	return 0;
}
