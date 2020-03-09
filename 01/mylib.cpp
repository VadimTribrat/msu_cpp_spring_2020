#include "mylib.h"
#include <cstring>
#include <cstdlib>
#include <iostream>

char * ptr_first;
char * ptr_last,* ptr_middle;


void makeAllocator(size_t maxSize)
{
	ptr_first = (char*)malloc(sizeof(char)* maxSize);
	ptr_last = ptr_first+maxSize;
	ptr_middle = ptr_first;
	if (ptr_first == nullptr)
	{
		std::cout << "Incorrect input\n";
		free(ptr_first);
		exit(0);
	}
	std::cout <<"Memory is allocated\n";

}

char * alloc(size_t size)
{
	char * tmp = ptr_middle;
	if (ptr_last - ptr_middle >= size)
	{
		ptr_middle = ptr_middle + size;
		std:: cout << "Successful allocated " << ptr_middle - tmp <<std:: endl;
		return tmp;
	}
	else
	{
		std::cout << "Enough memory for " << size << std::endl;
		return nullptr;
	}
}

void reset()
{
	std::cout << "Call reset()\n";
	ptr_middle = ptr_first;
}


