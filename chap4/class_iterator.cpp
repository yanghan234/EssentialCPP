// Construct an iterator for a class
#include <iostream>
#include <vector>
using namespace std;

class Fibonacci_iterator
{
    public:
        Fibonacci_iterator( int index ) : _index( index ) {};
        int operator*() const;
        bool operator==(const Fibonacci_iterator& ) const;
        bool operator!=(const Fibonacci_iterator& ) const;
        bool operator<(const Fibonacci_iterator& ) const;

        Fibonacci_iterator& operator++(); // prefix
        Fibonacci_iterator  operator++(int); // postfix

    private:
        int _index;
};

class Fibonacci
{
    friend class Fibonacci_iterator;
    public:
        Fibonacci();
        Fibonacci( int len );
        int gen_elem_by_index( int i );
        int elems(int i) const { return _elems[i]; };

        // copy assignment operator
        // 即，重载了等于号
        Fibonacci& operator=( const Fibonacci & );

        typedef Fibonacci_iterator iterator;

        iterator begin() const { return iterator( _begin );}
        iterator end() const { return iterator( _end );}

    private:
        int _len;
        int _begin;
        int _end;
        static vector<int> _elems;
};

vector<int> Fibonacci::_elems;

Fibonacci::Fibonacci( int len )
{
    _len = len;
    _begin = 0;
    _end = _begin + _len;
    for ( int i = 0; i < _len; i++ ) {
        _elems.push_back(gen_elem_by_index( i ));
    }
}

int Fibonacci::gen_elem_by_index( int i )
{
    if ( i == 0 or i == 1) {
        return 1;
    } else {
        return _elems[i-1] + _elems[i-2];
    }
}

Fibonacci& Fibonacci::operator=( const Fibonacci &rhs )
{
    this->_len = rhs._len;
    this->_begin = rhs._begin;
    this->_end = rhs._end;
    for ( int i = 0; i < _len; i++ ) {
        this->_elems[i] = rhs._elems[i];
    }
    return *this;
}

int Fibonacci_iterator::operator*() const
{
    return Fibonacci::_elems[ _index ];
}

bool Fibonacci_iterator::operator==(const Fibonacci_iterator &rhs ) const
{
    return this->_index == rhs._index;
}

bool Fibonacci_iterator::operator!=(const Fibonacci_iterator &rhs ) const
{
    return !( *this == rhs );
}

bool Fibonacci_iterator::operator<(const Fibonacci_iterator &rhs ) const
{
    return this->_index < rhs._index;
}

Fibonacci_iterator& Fibonacci_iterator::operator++()
{
    ++_index;
    return *this;
}

Fibonacci_iterator  Fibonacci_iterator::operator++(int)
{
    Fibonacci_iterator tmp = *this;
    ++_index;
    return tmp;
}

int main()
{
    int size = 10;
    Fibonacci fib(size);
    Fibonacci fib2(8);
    cout << "Elements in the vector are:" << endl;
    for ( int i = 0; i<size; i++ ) {
        cout << fib.elems(i) << ", ";
    }
    cout << endl;

    Fibonacci::iterator it = fib.begin();
    cout << *it << endl;
    it++;
    cout << *it << endl;
    it++;
    cout << *it << endl;
    it = fib.begin();

    cout << "Elements in the vector are: ( using iterator ) " << endl;
    for ( ; it < fib.end(); it++ ) {
        cout << *it << ", ";
    }
    cout << endl;

    Fibonacci::iterator it2 = fib2.begin();
    cout << "Elements in fib2 are: ( 8 elements ) " << endl;
    for ( ; it2 < fib2.end(); it2 ++ ) {
        cout << *it2 << ", ";
    }
    cout << endl;
    fib2 = fib;

    cout << "Elements in fib2 are: ( overloading copy from fib1 ) " << endl;
    it2 = fib2.begin();
    for ( ; it2 < fib2.end(); it2 ++ ) {
        cout << *it2 << ", ";
    }
    cout << endl;

}
