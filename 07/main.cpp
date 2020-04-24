#include <iostream>
#include "mylib.h"
#include <sstream>
#include <assert.h>

int main()
{
    Vector<int> vi1;
    Vector<int> vi2(5);

    assert(vi1.size() == 0 && vi1.capacity() == 0);
    assert(vi2.size() == 5 && vi2.capacity() == 5);

    assert(vi1.empty());
    assert(!vi2.empty());

    vi1.pop_back();
    vi2.pop_back();
    assert(vi2.size() == 4);
    
    return 0;
}
