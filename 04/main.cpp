#include "mylib.h"
#include <iostream>
#include <sstream>

using namespace std;

struct Data {
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer& serializer)
    {
        return serializer(a, b, c);
    }

public:
    Data(uint64_t a_, bool bo, uint64_t b)
        : a(a_)
        , b(bo)
        , c(b)
    {
    }
	friend ostream& operator<<(ostream& cout, Data& d);
};
ostream & operator <<(ostream & out, Data &d)
{
	std::string str;
	if (d.b)
		str = "true";
	else
		str = "false";
	out << d.a << " " << str << " " << d.c;
	return out;
}

int main(int argc, char** argv)
{
    Data x(1, false, 2);

    std::stringstream stream;
    std::cout << "Serialization object: ";
    std::cout << x << std::endl;
    Serializer serializer(stream);
    serializer.save(x);

    Data y(0, false, 0);

	
    Deserializer deserializer(stream);
    const Error err = deserializer.load(y);
    std::cout << "Deserialization: ";
    std::cout << y << std::endl;
    return 0;
}
