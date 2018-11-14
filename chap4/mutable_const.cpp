#include <iostream>
#include <vector>
using namespace std;

class Fibonacci{
    public:
        // constructor
        Fibonacci( ); // default
        Fibonacci( int len ); // length of the series, starting from 1
        Fibonacci( int len, int beg_pos ); // starting from beg_pos

        int length( ) const { return _length; }
        int beg_pos( ) const { return _beg_pos; }
        int elem( int pos ) const { return _elems[pos]; }

        int length2( )  { return _length; }
        int beg_pos2( ) { return _beg_pos; }
        int elem2( int pos ) { return _elems[pos]; }

        void modify_elems ( ) const;

        void repr( );

    private:
        int _length;
        int _beg_pos;
        int _next;
        mutable vector<int> _elems;
        vector<int> compute_elems( const int & );
};

Fibonacci::Fibonacci( )
{
    _length = 1;
    _beg_pos = 1;
    _next = 2;
    _elems = compute_elems(_length);
}

Fibonacci::Fibonacci( int len ) : _length(len)
{
    _beg_pos = 1;
    _next = 2;
    _elems = compute_elems(_length);
}

// The list after column(:) is called member initialization list.成员初始化列表
Fibonacci::Fibonacci( int len, int beg_pos ) : _length(len), _beg_pos(beg_pos)
{
    _next = beg_pos + 1;
    _elems = compute_elems(_length);
}

void Fibonacci::repr( )
{
    cout << _length << _beg_pos << _next << endl;
}

vector<int> Fibonacci::compute_elems( const int &len )
{
    int a[len];
    for ( int i = 0; i < len; i++ ){
        if ( i == 0 ){
            a[i] = 1;
        } else if ( i == 1 ){
            a[i] = 1;
        } else if ( i >= 2 ){
            a[i] = a[i-1] + a[i-2];
        }
    }
    vector<int> tmp(a,a+len);
    return tmp;
}

void Fibonacci::modify_elems( ) const
{
    for ( int i = 0; i < _length; i++ ){
        _elems[i] = _elems[i] + 1;
    }
}


int sum( const Fibonacci &fib )
{
    // 这里fib作为const reference 传入sum函数
    // 因此在sum函数中一定不可以改变fib中的数值，只能提取其中数值
    // 因此在此函数中调用的Fibonacci类中函数必须带有const标记，
    // 以告诉编译器，被调用的函数不改变fib的值
    int s = 0;
    for ( int i = 0; i < fib.length(); i++ ){
        s += fib.elem(i);
    }
    // _elems有mutable标记，因此即使在const reference之下,
    // 也可以调用会修改_elems数值的函数
    fib.modify_elems();
    return s;
}

int sum2( Fibonacci &fib )
{
    // sum2中的参数仅为fib的reference而不是const reference,
    // 因此此函数中可以调用fib的不带const标记的函数
    int s = 0;
    for ( int i = 0; i < fib.length2(); i++ ){
        s += fib.elem2(i);
    }
    return s;
}

int main()
{
    Fibonacci f(10,1);
    cout << f.length() << endl;
    cout << f.beg_pos() << endl;
    cout << sum(f) << endl;
    cout << sum2(f) << endl;

}

