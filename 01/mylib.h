#pragma once
#include <cstring>
#include <cstdlib>

void makeAllocator(size_t naxSize);
char * alloc(size_t size);
void reset();

