#include <vector>

class bigInt
{
	size_t size;
	std::vector<int> arr_of_int;
	bool neg;
	public:
	bigInt(const char *);
	bigInt(std::string str);
	~bigInt();
	bigInt(const bigInt&);
	bigInt operator=(const bigInt&);
	bool operator ==(const bigInt&);
	bigInt operator-() const;
	bool operator!=(const bigInt& other);
	bool operator<(const bigInt& other);
	bool operator>(const bigInt& other);
	bool operator>=(const bigInt& other);
	bool operator<=(const bigInt& other);
	friend bigInt operator +(const bigInt&, const bigInt&);
	friend bigInt operator -(const bigInt&, const bigInt&);
	friend std::ostream & operator <<(std::ostream & out,const bigInt& obj);
};
