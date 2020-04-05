#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include "mylib.h"

int max(int a, int b)
{
	return a > b? a: b;
}
int min(int a, int b)
{
	return a < b? a : b;
}
bigInt::bigInt(const char *  str1)
{
	std::string str(str1);
	neg = str[0] == '-';
	for(auto s:str)
	{
		if (s!= '-')
			arr_of_int.push_back(s - '0');
	}
	size = arr_of_int.size();
}
bigInt::bigInt(std::string str)
{
	neg = str[0] == '-';
	for(auto s:str)
	{
		if (s!= '-')
			arr_of_int.push_back(s - '0');
	}
	size = arr_of_int.size();
}

bigInt::~bigInt()
{
	arr_of_int.clear();
}
std::ostream & operator <<(std::ostream & out, const bigInt& obj)
{
	if (obj.neg)
		out << "-";
	for(auto s:obj.arr_of_int)
		out<< s;
	return out;
}
bigInt operator +(const bigInt & a, const bigInt & b)
{
	int flag = 0;
	int sizea = a.size-1, sizeb = b.size-1;
	int s = max(sizea, sizeb);
	std::string str("");
	if (!a.neg && b.neg)
		return a-(-b);
	if (a.neg && !b.neg)
		return b-(-a);
	if (a.neg && b.neg)
		return -((-a) + (-b));
	if (!a.neg && !b.neg)
	{
		for(int i = s; i>=0; i--)
		{
			if (sizea < 0)
			{
				int s = b.arr_of_int[sizeb];
				s += flag;
				str.push_back((char)((s%10)+'0'));
				flag = s/10;
				sizeb--;
				continue;
			}
			if(sizeb < 0)
			{
				int s = a.arr_of_int[sizea];
				s += flag;
				str.push_back((char)((s%10) + '0'));
				flag = s/10;
				sizea--;
				continue;
			}
				int s = a.arr_of_int[sizea] + b.arr_of_int[sizeb];
				s += flag;
				str.push_back((char)((s%10)+'0'));
				flag = s/10;
				sizea--;
				sizeb--;
		}
		if (flag)
			str.push_back((char)(flag + '0'));
		std::reverse(str.begin(), str.end());
		return bigInt(str);
	}
}
bigInt::bigInt(const bigInt & obj)
{
	arr_of_int = obj.arr_of_int;
	size = obj.size;
	neg = obj.neg;
}
bool bigInt::operator ==(const bigInt & obj)
{
	if (size != obj.size)
		return false;
	if (neg != obj.neg)
		return false;
	bool flag = true;
	for (size_t i =0 ; i< size; i++)
	{
		flag = arr_of_int[i] == obj.arr_of_int[i];
		if (!flag)
			return flag;
	}
	return flag;
}
bool bigInt::operator !=(const bigInt & obj)
{
	return !((*this)==obj);
}
bool bigInt::operator <=(const bigInt & obj)
{
	if (neg && !obj.neg)
		return true;
	if (!neg && obj.neg)
		return false;
	if (neg && obj.neg)
	{
		if (size < obj.size)
			return false;
		if (size > obj.size)
			return true;
		bool flag = true;
		for (size_t i = 0; i<size; i++)
		{
			flag = arr_of_int[i] >= obj.arr_of_int[i];
			if (!flag)
				return flag;
		}
		return flag;
	}
	if (!neg && !obj.neg)
	{
		if (size < obj.size)
			return true;
		if (size > obj.size)
			return false;
		bool flag = true;
		for (size_t i = 0; i<size; i++)
		{
			flag = arr_of_int[i] <= obj.arr_of_int[i];
			if (!flag)
				return flag;
		}
		return flag;
	}	
}
bool bigInt::operator>=(const bigInt& obj)
{
	if (neg && !obj.neg)
		return false;
	if (!neg && obj.neg)
		return true;
	if (neg && obj.neg)
	{
		if (size < obj.size)
			return true;
		if (size > obj.size)
			return false;
		bool flag = true;
		for (size_t i = 0; i<size; i++)
		{
			flag = arr_of_int[i] <= obj.arr_of_int[i];
			if (!flag)
				return flag;
		}
		return flag;
	}
	if (!neg && !obj.neg)
	{
		if (size < obj.size)
			return false;
		if (size > obj.size)
			return true;
		bool flag = true;
		for (size_t i = 0; i<size; i++)
		{
			flag = arr_of_int[i] >= obj.arr_of_int[i];
			if (!flag)
				return flag;
		}
		return flag;
	}	
}
bool bigInt::operator<(const bigInt& other)
{
	bool flag = ((*this)<=other);
	return flag && (*this)!=other;
}
bool bigInt::operator>(const bigInt& other)
{
	return !((*this)>=other) && (*this) != other;
}
bigInt operator -(const bigInt & a, const bigInt & b)
{
	int sizea = a.size - 1, sizeb = b.size - 1;
	bigInt inc(""), dec("");
	bool flag = true;
	if (!a.neg && b.neg)
		return a+(-b);
	if (a.neg && !b.neg)
		return -(-a+b);
	if (a.neg && b.neg)
		return (-b)-(-a);
	if (!a.neg && !b.neg)
	{
		if (sizea >= sizeb)
		{
			int * s = new int[a.size + 1];
			std::string str("");
			for (int i = 0; i < a.size+1; i++)
				s[i] = 0;
			int mi = min(sizea, sizeb);
			int ma = max(sizea, sizeb);
			for (int i = 0; i <= mi; i++)
			{
				int temp = a.arr_of_int[sizea] - b.arr_of_int[sizeb] - s[sizea+1];
				if (temp >= 0)
					str.push_back((char)(temp + '0'));
				else
				{
					s[sizea] += 1;
					str.push_back((char)(temp + 10 + '0'));
				}
				sizeb--;
				sizea--;
			}
			for (int i =mi+1  ; i<= ma; i++)
			{
				int temp = a.arr_of_int[sizea] - s[sizea + 1];
				if (temp >= 0)
					str.push_back((char)(temp + '0'));
				else
				{
					s[sizea] += 1;
					str.push_back((char)(temp + 10 + '0'));
				}
				sizeb--;
				sizea--;
	
			}
			free(s);
			std::reverse(str.begin(), str.end());
			std::string tempstr("");
			size_t i = 0;
			while (str[i] == '0')
				i++;
			for(size_t j = i; j<str.size(); j++)
				tempstr.push_back(str[j]);
//			std::reverse(tempstr.begin(), tempstr.end());
			if (tempstr.size()== 0)
				tempstr.push_back('0');
			return bigInt(tempstr);
		}
		else
		{
		int * s = new int[b.size + 1];
		std::string str("");
		for (int i = 0; i < b.size+1; i++)
			s[i] = 0;
		int mi = min(sizea, sizeb);
		int ma = max(sizea, sizeb);
		for (int i = 0; i <= mi; i++)
		{
			int temp = b.arr_of_int[sizeb] - a.arr_of_int[sizea] - s[sizeb+1];
			if (temp >= 0)
				str.push_back((char)(temp + '0'));
			else
			{
				s[sizeb] += 1;
				str.push_back((char)(temp + 10 + '0'));
			}
			sizeb--;
			sizea--;
		}
		for (int i =mi+1  ; i<= ma; i++)
		{
			int temp = b.arr_of_int[sizeb] - s[sizeb + 1];
			if (temp >= 0)
				str.push_back((char)(temp + '0'));
			else
			{
				s[sizeb] += 1;
				str.push_back((char)(temp + 10 + '0'));
			}
			sizeb--;
			sizea--;

		}
		str.push_back('-');
		std::reverse(str.begin(), str.end());
		std::string tempstr("");
		size_t i = 1;
		while (str[i] == '0')
			i++;
		for(size_t j = i; j<str.size(); j++)
			tempstr.push_back(str[j]);
		tempstr.push_back('-');
//		std::reverse(tempstr.begin(), tempstr.end());
		if (tempstr.size()== 1)
			tempstr.push_back('0');
		free(s);
		return bigInt(std::string("-")+tempstr);
	}
	}
			
}
bigInt bigInt::operator =(const bigInt & obj)
{
	arr_of_int = obj.arr_of_int;
	size = obj.size;
	neg = obj.neg;
	return *this;
}
bigInt bigInt::operator -()const
{
	bigInt temp = *this;
	temp.neg = !temp.neg;
	return temp;
}
