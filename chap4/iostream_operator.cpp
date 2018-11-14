#include <iostream>
#include <vector>
using namespace std;

class Fibonacci
{
    public:
        Fibonacci( unsigned int len );
        void display();
        unsigned int len() const { return _len; };
        unsigned int elems( unsigned int i ) const { return _elems[i]; };



    private:
        unsigned int _len;
        vector<int>  _elems;
        void  _gen_elems( );

};

ostream& operator<<(ostream &os, const Fibonacci &rhs)
{
    os << "Display elements by overloading ostream:" << endl;
    for ( unsigned int i = 0; i < rhs.len()-1; i++ )
        os << rhs.elems(i) << ", ";
    os << rhs.elems(rhs.len()-1) << endl;
    return os;
}

Fibonacci::Fibonacci( unsigned int len )
{
    _len = len;
    _gen_elems( );
}

void Fibonacci::_gen_elems( )
{
    for ( unsigned int i = 0; i < _len; i++ ) {
        if ( i == 0 ) { _elems.push_back(1); }
        else if ( i == 1 ) { _elems.push_back(1); }
        else { _elems.push_back( _elems[i-1] + _elems[i-2] ); }
    }
}

void Fibonacci::display( )
{
    for ( unsigned int i = 0; i < _len-1; i++ )
        cout << _elems[i] << ", ";
    cout << _elems[_len-1] << endl;
}

int main()
{
    Fibonacci fib(10);
    cout << " Display the vector:" << endl;
    fib.display( );

    cout << fib;

}
