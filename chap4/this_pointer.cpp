#include <iostream>
using namespace std;

class matrix
{
    public:
        matrix& copy( matrix &mat );
        matrix( ) : _nrow(0), _ncol(0){};
        matrix(int nrow, int ncol) : _nrow(nrow), _ncol(ncol){};

        int nrow(){ return _nrow; }
        int ncol(){ return _ncol; }
    private:
        int _nrow;
        int _ncol;
};


matrix& matrix::copy( matrix &mat )
{
    // this指针，指代当前类
    if ( this != &mat ){
        this->_nrow = mat._nrow;
        this->_ncol = mat._ncol;
    }
    return *this;
}

int main()
{
    matrix mat(3,2);
    matrix mat2;
    mat2.copy( mat );
    cout << mat2.nrow() << ", " << mat2.ncol() << endl;
}


