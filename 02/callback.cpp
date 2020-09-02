#include "callback.h"
#include <cstdlib>
#include <iostream>

using onNum = void (*)(int);
using onStr = void (*)(const std::string &);
using before = void (*)();

onNum Num = nullptr;
onStr Str = nullptr;
before frst = nullptr, lst = nullptr;

void onNumber(onNum foo)
{
	Num = foo;	
}

void onSym(onStr foo)
{
	Str = foo;	
}

void first(before foo)
{
	frst = foo;	
}

void last(before foo)
{
	lst = foo;	
}

void parse(const std::string & str)
{
	frst();
	if (!str.empty())
	{
		for(size_t i = 0; i<str.length(); i++)
		{
			char c = str[i];
			size_t j;
			if ((c == ' ') || (c == '\t') || (c == '\n'))
				continue;
			std::string word;
			for(j = i; j<str.length(); j++)
			{
				char s = str[j];
				if ((s != ' ') && (s != '\t') && (s != '\n'))
					word.push_back(s);
				else
					break;
			}
			i = j;
			if (word[0]>'0' && word[0]<'9')
				Num(atoi(word.c_str()));
			else		
				Str(word);
		}
	}
	lst();	
}

