#include "mylib.h"
#include <iostream>
#include <sstream>

using namespace std;

class Data
{
	int a;
	bool b;
	int c;
	public:
	Data(int a_t, bool b_t, int c_t):a{a_t}, b{b_t}, c{c_t}
	{}
	template <class T>
	Error serialize(T & t)
	{
		return t(a, b, c);
	}
	friend std::ostream & operator <<(std::ostream & out,const Data & d);
};

std::ostream & operator<<(std::ostream & out, const Data & d)
{
	out << "a: " << d.a << " b: " << std::boolalpha << d.b << " c: " << d.c << std::endl;
	return out;
}	

int main()
{
	Data d(1, true, 2);
	stringstream out;
	Serializer ser(out);
	Deserializer deser(out);
	cout << d;
	ser.save(d);
	Data y(100, false, 0);
	deser.load(y);
	cout << y;	
	return 0;
}
