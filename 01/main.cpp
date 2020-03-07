#include <iostream>
#include <cstdlib>
#include <string>

char * ptr_first = nullptr;
char * ptr_last, * ptr_middle;

void makeAllocator(size_t naxSize);
char * alloc(size_t size);
void reset();

int main(int argc, char * * argv)
{
	std::cout << "\n";
	if (argc > 1)
	{
		char * a = nullptr, c = 'a';
		int * in = (int *) malloc(sizeof(int) * (argc - 1));
		for (int i = 0; i < argc-1; i++)
			in[i] = atoi(argv[i+1]);
		makeAllocator(in[0]);
		for (int i = 1; i < argc - 1; i++)
		{
			a = alloc(in[i]);
			if (a != nullptr)
			{
				*a = c;
				std:: cout << *a << std::endl;
				c++;
			}
			if (i == 2)
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

void makeAllocator(size_t maxSize)
{
	ptr_first = (char*) malloc(sizeof(char) * maxSize);
	ptr_last = ptr_first + maxSize;
	ptr_middle = ptr_first;
	if (ptr_first == nullptr)
	{
		std::cout << "Incorrect input\n";
		free(ptr_first);
		exit(0);
	}
	std::cout << "Memory is allocated\n";

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


