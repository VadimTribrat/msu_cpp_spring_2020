#include <cstring>
#include <cstdlib>
#include <iostream>
#include "mylib.h"

using On = void (*)(char *);
using At = void (*)();
On onNumber, onString;
At first, end;
void register_on_number(On callback)
{
	onNumber = callback;
}
void register_on_string(On callback)
{
	onString = callback;
}
void register_first(At call)
{
	first = call;
}
void register_end(At call)
{
	end = call;
}

void parse(const char * text)
{
	const char * ptr = text, * ptr1 = text;
        char * src;
	first();
	while (*ptr != '\0')
		{
			int i = 0;
			while ((*ptr ==' ') || (*ptr == '\t') || (*ptr == '\n'))
				ptr += 1;
			if (*ptr == '\0')
				continue;
			if ((*ptr <= '9') && (*ptr >= '0'))
			{
				ptr1 = ptr;
				i = 0;
				while((*ptr <= '9') && (*ptr >= '0'))
				{
					i++;
					ptr++;
				}
				src = (char *) malloc(sizeof(char)* (i+1));
				strncpy(src, ptr1, i);
				src[i] = '\0';
//				std::cout << src << std::endl;
				onNumber(src);
			}
			else
			{
				ptr1 = ptr;
				i = 0;
				while((*ptr !=' ') && (*ptr != '\t') && (*ptr != '\n') &&( (*ptr > '9') || (*ptr < '0')))
				{
					i++;
					ptr++;
					if (*ptr == '\0')
					{
						i--;
						break;
					}
				}
				src = (char *) malloc(sizeof(char) * (i+1));
				strncpy(src, ptr1, i);
				src[i] = '\0';
//				std::cout << src << std:: endl;
				onString(src);
			}
		}
	end();
		
}
