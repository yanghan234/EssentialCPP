#include <iostream>
using namespace std;

class A
{
    public:
        int get_elem();
};

class B
{
    friend class A;
    public:
        B( int elem );

    private:
        static int _elem;

};

B::B( int elem ) { _elem = elem; }

int get_elem()
{
    return B::_elem;
}

int main()
{
    B b(1);
    A a;

}
