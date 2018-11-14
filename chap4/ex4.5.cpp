#include <vector>
#include <iostream>
using namespace std;

class Matrix
{
    public:
        Matrix( ){};
        Matrix( unsigned int row, unsigned int col );
        void values( const float *, const float *);
        unsigned int row() const { return _row; };
        unsigned int col() const { return _col; };
        void display( ) const;

        float operator() ( unsigned int irow, unsigned int icol ) const;
        Matrix& operator=( const Matrix &rhs );
        Matrix& operator+=( const Matrix &rhs );


    private:
        unsigned int _row;
        unsigned int _col;
        unsigned int max_size;
        vector<float> _mat;

};

Matrix::Matrix( unsigned int row, unsigned int col )
{
    _row = row;
    _col = col;
    _mat.reserve( _row * _col );
}


void Matrix::values( const float *begin, const float *end )
{
    _mat.assign(begin,end);
}

void Matrix::display( ) const
{
    for ( unsigned int irow = 0; irow < _row; irow++ ) {
        for ( unsigned int icol = 0; icol < _col-1; icol++ ) {
            cout << _mat[ irow * _col + icol ] << ", ";
        }
        cout << _mat[ irow*_col + _col - 1 ] << endl;
    }
}

inline float Matrix::operator() ( unsigned int irow, unsigned int icol ) const
{
    return _mat[ irow * _col + icol ];
}

ostream& operator<<( ostream& os, const Matrix &rhs )
{
    os << "Elements in the matrix are:" << endl;
    for ( unsigned int irow = 0; irow < rhs.row(); irow++ ) {
        for ( unsigned int icol = 0; icol < rhs.col()-1; icol++ ) {
            os << rhs(irow,icol) << ", ";
        }
        os << rhs(irow,rhs.col()-1) << ";" << endl;
    }
    return os;
}

Matrix& Matrix::operator=( const Matrix &rhs )
{
    this->_row = rhs._row;
    this->_col = rhs._col;
    this->_mat.reserve(this->_row * this->_col);
    this->_mat.assign(rhs._mat.begin(), rhs._mat.end());
    return *this;
}

Matrix& Matrix::operator+=( const Matrix &rhs )
{
    if ( this->_row == rhs._row and this->_col == rhs._col )
        for ( unsigned int i = 0; i < _row*_col; i++ )
            this->_mat[i] += rhs._mat[i];
    return *this;
}

int main()
{
    const unsigned row=2,col=2;
    float arr[ row*col ];
    Matrix mat(row,col);
    Matrix mat2;

    for ( unsigned irow = 0; irow < row; irow++ )
        for ( unsigned icol = 0; icol < col; icol++ )
            arr[ irow*col+icol ] = irow*2.0+icol;

    cout << arr[0] <<", "<< arr[1] << endl;
    cout << arr[2] <<", "<< arr[3] << endl;

    mat.values( arr, arr+row*col );

    cout << mat;

    mat2 = mat;

    cout << mat2;

    mat2 += mat;

    cout << mat2;

}
