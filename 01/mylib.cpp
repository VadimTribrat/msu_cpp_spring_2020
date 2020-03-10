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
}

char * alloc(size_t size)
{
	char * tmp = ptr_middle;
	if (ptr_last - ptr_middle >= size)
	{
		ptr_middle = ptr_middle + size;
		return tmp;
	}
	else
	{
		return nullptr;
	}
}

void reset()
{
	ptr_middle = ptr_first;
}


