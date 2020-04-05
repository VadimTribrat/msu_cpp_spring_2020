#include <iostream>
#include "mylib.h"

using namespace std;

int main(int argc, char * * argv)
{
	bigInt big("-12345678900000");
	cout << big << endl;
	cout << big << '+' << big << " = " << big+big << endl;
	cout << big << "-" << big << " = " << big-big << endl;
	cout << "-(" << big << ") = " << -big << endl;
	cout << "-(" << big << ") - " << big << " = " << -big - big << endl;
	cout << bigInt("123456") << " - " << bigInt("321") << " = " << bigInt("123456") - bigInt("321") << endl;
	cout << bigInt("321") << " - " << bigInt("123456") << " = " << bigInt("321") - bigInt("123456") << endl;
	cout << bigInt("321") << " < " << bigInt("123456") << " : " << (bigInt("321") < bigInt("123456")) << endl;
	cout << bigInt("321") << " > " << bigInt("123456") << " : " << (bigInt("321") < bigInt("123456")) << endl;
	cout << bigInt("-9999999999321") << " <= " << bigInt("1234560000000000") << " : " << (bigInt("-9999999999321") <= bigInt("1234560000000000")) << endl;
	cout << bigInt("-321") << " == " << bigInt("321") << " : " << (bigInt("-321") == bigInt("321")) << endl;
	cout << bigInt("321") << " == " << bigInt("321") << " : " << (bigInt("321") == bigInt("321")) << endl;
	cout << bigInt("321") << " != " << bigInt("321") << " : " << (bigInt("321") != bigInt("321")) << endl;

	return 0;
}
