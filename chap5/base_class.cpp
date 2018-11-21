#include <iostream>
#include <vector>
using namespace std;

class num_seq
{
    public:
        virtual ~num_seq(){};

        virtual int             elem( int pos ) const = 0; // pure virtual function
        virtual const char*     what_am_i() const = 0;
        static int              max_elems() { return _max_elems; };
        virtual ostream&        print( ostream &os = cout ) const = 0;

    protected:
        virtual void            gen_elems( int pos ) const = 0;
        bool                    check_integrity( int pos ) const;
        const static int        _max_elems = 1024;
};

bool num_seq::check_integrity( int pos ) const
{
    if ( pos <= 0 || pos > _max_elems )
    {
        cerr << "!! invalid position: " << pos
             << " Cannot honor request\n";
        return false;
    }
    return true;
}

ostream& operator<<( ostream &os, const num_seq &ns )
{
    return ns.print( os );
}

// Define a derived class
class Fibonacci : public num_seq
{
    public:
        Fibonacci(  int len = 1, int beg_pos = 1 );

        virtual int             elem( int pos ) const;
        virtual const char*     what_am_i() const { return "Fibonacci"; };
        virtual ostream&        print( ostream &os = cout ) const;
        int                     length() const { return _length; };
        int                     beg_pos() const { return _beg_pos; };

    protected:
        int _length;
        int _beg_pos;
        virtual void            gen_elems( int pos ) const;
        static vector<int>      _elems;
};

vector<int> Fibonacci::_elems;

Fibonacci::Fibonacci( int len, int beg_pos )
{
    _length = len;
    _beg_pos = beg_pos;
    gen_elems( len );
}

int Fibonacci::elem( int pos ) const
{
    if ( ! check_integrity( pos ) )
        return 0;

    if ( pos > static_cast<int>(_elems.size()) )
        Fibonacci::gen_elems( pos );

    return _elems[ pos-1 ];
}

void Fibonacci::gen_elems( int pos ) const
{
    if ( _elems.empty() )
    {
        _elems.push_back( 1 );
        _elems.push_back( 1 );
    }

    if ( static_cast<int>(_elems.size()) <= pos )
    {
        int ix = _elems.size();
        int n_2 = _elems[ ix-2 ];
        int n_1 = _elems[ ix-1 ];

        for ( ; ix <= pos; ++ix )
        {
            int elem = n_2 + n_1;
            _elems.push_back( elem );
            n_2 = n_1;
            n_1 = elem;
        }
    }
}

ostream& Fibonacci::
print( ostream &os ) const
{
    int elem_pos = _beg_pos - 1;
    int end_pos  = elem_pos + _length;

    if ( end_pos > static_cast<int>(_elems.size()) )
        Fibonacci::gen_elems( end_pos );

    while ( elem_pos < end_pos )
        os << _elems[ elem_pos++ ] << ' ';

    return os;
}


int main()
{
    /* num_seq has pure virtual functions,
     * the following statement is illegal.
     */
    // num_seq seq;
    // cout << seq.max_elems() << endl;

    num_seq *ps = new Fibonacci( 12, 5 );
    cout << ps->what_am_i() << endl;
    ps->print( cout );

    num_seq *ps2 = new Fibonacci(13);
    cout << ps2->what_am_i() << endl;
    ps2->print( cout );



}


