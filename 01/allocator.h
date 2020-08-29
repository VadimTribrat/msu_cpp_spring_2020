#pragma once
#include <cstdlib>

void makeAllocator(size_t maxsize);
char * alloc(size_t size);
void reset();
void del();
