#include <iostream>
#include <vector>
using namespace std;

template <int len>
class Fibonacci
{
    public:
        Fibonacci( int beg_pos = 1 ) : _length(len), _beg_pos(beg_pos) { gen_elems(); };
        int elem( int ind ) const { return _elems[ind]; };
        int beg_pos() const { return _beg_pos; };
        int length() const { return _length; };

    private:
        int _beg_pos;
        int _length;
        vector<int> _elems;
        void gen_elems( );

};

template <int len>
void Fibonacci<len>::gen_elems( )
{
    for ( unsigned int i = 0; i < len; i++ )
    {
        if ( i == 0 || i == 1 ) _elems.push_back(1);
        else _elems.push_back( _elems[i-1] + _elems[i-2] );
    }
}

template <int len>
ostream& operator<<(ostream &os, const Fibonacci<len> &rhs )
{
    os << "( " << rhs.beg_pos() << ", " << rhs.length() << " )";
    for ( unsigned i = 0; i < rhs.length(); i++ )
        os << rhs.elem(i) <<", ";
    os << endl;
    return os;
}

int main()
{
    Fibonacci<10> fib;

    cout << fib;

}
