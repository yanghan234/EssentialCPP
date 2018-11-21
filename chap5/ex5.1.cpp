#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Stack
{
    public:
        virtual bool pop( string& ) = 0;
        virtual bool push( const string& ) = 0;
        virtual bool peek( int, string& ) = 0;

        virtual int top( ) const = 0;
        virtual int size( ) const = 0;

        virtual bool empty( ) const = 0;
        virtual bool full( ) const = 0;
        virtual void print( ostream &os = cout ) const = 0;
};

ostream& operator<<( ostream &os, const Stack &rhs )
{
    rhs.print( );
    return os;
}

class LIFO_stack : public Stack
{
    public:
        LIFO_stack( int capacity = 0 ) : _top( 0 )
        {
            if ( capacity )
                _max_size = capacity;
                _stack.reserve( capacity );
        }

        int  size() const { return _stack.size(); };
        bool empty() const { return !_top; };
        bool full() const { return _top >= _max_size; };
        int  top() const { return _top; };
        void print( ostream &os = cout ) const;

        bool pop( string &elem );
        bool push( const string &elem );
        bool peek( int, string& ) { return false; };

    private:
        int _top;
        int _max_size;
        vector<string> _stack;

};

bool LIFO_stack::pop( string &elem )
{
    if ( empty() ) return false;
    elem = _stack[ _top ];
    _top--;
    _stack.pop_back();
    return true;
}

bool LIFO_stack::push( const string &elem )
{
    if ( this->full() ) { return false; };
    _stack.push_back( elem );
    _top ++;
    return true;
}

void LIFO_stack::print( ostream &os ) const
{
    vector<string>::const_reverse_iterator rit = _stack.rbegin(), rend = _stack.rend();

    os << "\n\t";
    while ( rit != rend )
        os << *rit++ << "\n\t";
    os << endl;
}

void peek( Stack &st, int index )
{
    cout << endl;
    string t;
    if ( st.peek( index, t))
        cout << "peek:" << t;
    else cout << "peek failed!";
    cout << endl;
}

int main()
{
    LIFO_stack st(3);
    string str;
    while ( cin >> str && !st.full() )
        st.push( str );
    cout << '\n' << "About to call peek() with LIFO_stack" << endl;
    peek( st, st.top()-1 );
}
