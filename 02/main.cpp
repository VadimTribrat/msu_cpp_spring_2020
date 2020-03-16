#include <iostream>
#include "mylib.h"

void callback_number(char * text);
void callback_string(char *);
void first();
void end();

int main(int argc, char * * argv)
{
	std::cout << "\n\n";
	register_on_number(callback_number);
	register_on_string(callback_string);
	register_first(first);
	register_end(end);
	parse(argv[1]);
	std::cout << "\n\n";
	return 0;
}

void callback_number(char * text)
{
	std::cout << text << std::endl;
}
void callback_string(char * text)
{
	std::cout << text << std::endl;
}
void first()
{
	std::cout << "First\n";
}
void end()
{
	std::cout << "End\n";
}
