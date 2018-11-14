#include <iostream>
using namespace std;
// static data member表示唯一的可共享的成员
// 此成员可以被同一个类的所有对象所访问

class matrix
{
    public:
        matrix( ) : _nrow(0), _ncol(0){};
        matrix(int nrow, int ncol) : _nrow(nrow), _ncol(ncol) {};

        int nrow(){ return _nrow; }
        int ncol(){ return _ncol; }
        static int num; // static class member
        static int add_1(int num); // static class function
    private:
        int _nrow;
        int _ncol;
};

int matrix::num = 10;

int matrix::add_1(int num) // 定义时，无需再加static
{
    return num + 1;
}

int main()
{
    matrix mat1(4,5), mat2(3,4);
    cout << mat1.num << mat2.num << endl;
    mat1.num += 1;
    // 一个对象改变静态成员，其他对象中的静态成员也改变
    cout << mat1.num << mat2.num << endl;

    // 调用static function 无需指定对象，可以以类名调用static function
    mat1.num = matrix::add_1(mat1.num);
    cout << mat1.num << mat2.num << endl;






}


