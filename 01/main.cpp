#include "allocator.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char * * argv)
{
	int * * ptrs = nullptr, num_of_ptrs;
	cout << endl;
	num_of_ptrs = atoi(argv[1]);
	if ((argc <atoi(argv[1]) + 3) || (num_of_ptrs == 0))
	{
		return 0;
	}
	cout << "Num_of_ptrs " << num_of_ptrs << endl;
	makeAllocator(atoi(argv[2]));
	ptrs = new int *[num_of_ptrs];
	for(size_t i=0; i<num_of_ptrs; i++)
	{
		if(ptrs[i] = reinterpret_cast<int *>(alloc(atoi(argv[3+i]))))
		{
			*ptrs[i] = i+100'000;
			cout << *ptrs[i] << endl;
		}
		else
		{
			cout << "Memory not enough\n";
		}
	}
	cout << "--------\n";
	for(int i = num_of_ptrs - 1; i>=0; i--)
	{
		if(ptrs[i])
		{
			cout << *ptrs[i] << endl;
		}
		else
		{
			cout << "Memory not enough\n";
		}
	}
	cout << endl;
	return 0;
}
