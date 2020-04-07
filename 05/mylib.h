#include <vector>

class bigInt
{
	size_t size;
	size_t max_size;
	int * arr_of_int;
	bool neg;
	public:
//	bigInt(const char *);
	bigInt(std::string str);
	~bigInt();
	bigInt(const bigInt&);
	bigInt operator=(const bigInt&);
	bool operator ==(const bigInt&) const;
	bigInt operator-() const;
	bool operator!=(const bigInt& other) const;
	bool operator<(const bigInt& other)const;
	bool operator>(const bigInt& other)const;
	bool operator>=(const bigInt& other)const;
	bool operator<=(const bigInt& other)const;
	void push_back(int n);
	friend bigInt operator +(const bigInt&, const bigInt&);
	friend bigInt operator -(const bigInt&, const bigInt&);
	friend std::ostream & operator <<(std::ostream & out,const bigInt& obj);
};
