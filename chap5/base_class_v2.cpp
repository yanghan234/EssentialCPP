#include <iostream>
#include <vector>
using namespace std;

class num_seq
{
    public:
        virtual ~num_seq(){};
        virtual const char* what_am_i() const = 0;
        int                 elem( int pos ) const;
        ostream&            print( ostream &os = cout ) const;

        int                 length() const { return _length; };
        int                 beg_pos() const { return _beg_pos; };
        static int          max_elems() { return 64; };

    protected:
        int _length;
        int _beg_pos;
        vector<int> & _relems;  // reference to int vector
                                // remember, reference cannot be referred to null object
        num_seq( int len, int bp, vector<int> &re )
            : _length(len), _beg_pos(bp), _relems(re) {};
        virtual void gen_elems( int pos ) const = 0;
        bool         check_integrity( int pos, int size ) const;
};

class Fibonacci : num_seq
{
    public:
        Fibonacci( int len = 1, int beg_pos = 1 );
        virtual const char* what_am_i() const { return "Fibonacci"; };

    protected:
        virtual void gen_elems( int pos ) const;
        static vector<int> _elems;

};

vector<int> Fibonacci::_elems;

Fibonacci::Fibonacci( int len, int beg_pos )
    : num_seq( len, beg_pos, _elems ) { gen_elems( _length ); };

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

int main()
{
    Fibonacci fib;

}
