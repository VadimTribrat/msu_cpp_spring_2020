#include "callback.h"
#include <iostream>


using namespace std;

void callback_number(int text);
void callback_string(const std::string &);
void first1();
void end();

int main(int argc, char * * argv)
{
	string text;
	getline(cin, text);
	onNumber(callback_number);
	onSym(callback_string);
	first(first1);
	last(end);	
	parse(text);
	return 0;
}

void callback_number(int text)
{
	std::cout << text << std::endl;
}
void callback_string(const std::string & text)
{
	std::cout << text << std::endl;
}
void first1()
{
	std::cout << "First\n";
}
void end()
{
	std::cout << "End\n";
}
