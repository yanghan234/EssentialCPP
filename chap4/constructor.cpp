#include <iostream>
#include <vector>
using namespace std;

class Fibonacci{
    public:
        // constructor
        Fibonacci( ); // default
        Fibonacci( int len ); // length of the series, starting from 1
        Fibonacci( int len, int beg_pos ); // starting from beg_pos

        void repr( );

    private:
        int _length;
        int _beg_pos;
        int _next;
};

Fibonacci::Fibonacci( )
{
    _length = 1;
    _beg_pos = 1;
    _next = 2;
}

Fibonacci::Fibonacci( int len ) : _length(len)
{
    _beg_pos = 1;
    _next = 2;
}

// The list after column(:) is called member initialization list.成员初始化列表
Fibonacci::Fibonacci( int len, int beg_pos ) : _length(len), _beg_pos(beg_pos)
{
    _next = beg_pos + 1;
}

void Fibonacci::repr( )
{
    cout << _length << _beg_pos << _next << endl;
}

class Matrix{
    public:
        Matrix( int row, int col ) : _row(row), _col(col)
        {
            _pmat = new double[ _row * _col];
        };
        Matrix( const Matrix &rhs ) : _row(rhs._row), _col(rhs._col)
        {
            // overload the construct so that we can initialize a new
            // object based on an existing object
            // In this way, the _pmat in the new object will not be affected
            // by the execution of the detructor function in the old obj.
            // Otherwise, we will lost _pmat of the new obj.
            _pmat = new double[ _row * _col ];
        }

        // destructor
        // 析构函数
        ~Matrix(){
            delete[] _pmat;
        }

    private:
        int _row,_col;
        double * _pmat;
};

int main()
{
    Fibonacci f1, f2(3), f3(4,4);
    f1.repr();
    f2.repr();
    f3.repr();

    Matrix mat1(2,3);
    Matrix mat2(mat1);

}
