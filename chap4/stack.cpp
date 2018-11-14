#include <iostream>
#include <vector>
#include <string>
#include "stack.h"
using namespace std;

int main()
{
    stack s;
    string elem;
    s.push("hello!");
    cout << s.find("hello!") << endl;
    cout << s.count("hello!") << endl;
    s.peek(elem);
    cout << elem << endl;
    s.pop(elem);
    cout << elem << endl;


}
