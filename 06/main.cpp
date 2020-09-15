#include "format.h"
#include <iostream>
#include <tuple>

using namespace std;

int main(int argc, char * * argv)
{
	try
	{
		cout << format("0+1={0} 1+1={1} 0+1={0} 2+1={2}", 1, 2 , 3) << endl;
//		cout << format("0+1={0} 1+1={1} 0+1={0} 2+1={2", 1, 2 , 3) << endl;
		cout << format("0+1={0} 1+1={1} 0+1={0} 2+1={2}", 1, 2) << endl;		
	}
	catch(std::runtime_error Ex)
	{
		cout << Ex.what();
	}
	return 0;
}
