#include "mylib.h"
#include <iostream>
#include <cstdlib>
#include <string>

extern char * ptr_first;

int main(int argc, char * * argv)
{
	std::cout << "\n";
	if (argc >1)
	{
		char * a = nullptr, c = 'a';
		int * in =(int *) malloc(sizeof(int) * (argc -1));
		for (int i =0; i< argc-1; i++)
			in[i] = atoi(argv[i+1]);
		makeAllocator(in[0]);
		for (int i =1; i< argc - 1; i++)
		{
			a = alloc(in[i]);
			if (a != nullptr)
			{
				*a = c;
				std:: cout << *a << std::endl;
				c++;
			}
			if (i ==2)
				reset();
		}
		free(ptr_first);
		free(in);
		std::cout << "\n";
		return 0;
	}
	else
	{
		return 0;
	}
}

