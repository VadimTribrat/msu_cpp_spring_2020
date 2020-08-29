#include "allocator.h"
#include <cstdlib>

char * ptr = nullptr, * ptrFirst = nullptr, * ptrEnd = nullptr;

void makeAllocator(size_t maxSize)
{
	ptr = new char[maxSize];
	ptrEnd = ptr + maxSize;
	ptrFirst = ptr;
}

char * alloc(size_t size)
{
	if (!ptr)
		return nullptr;
	if (ptr + size <= ptrEnd)
	{
 		ptr += size;
		return ptr - size;
	}
	else
	{
		return nullptr;
	}	
}

void reset()
{
	ptr = ptrFirst;
}

void del()
{
	delete [] ptrFirst;
}
