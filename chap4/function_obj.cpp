#include <iostream>
using namespace std;

// 所谓function object,其实就是一种提供function call运算符的class

class LessThan
{
    public:
        LessThan( int val ) : _val(val) {};
        int comp_val() const { return _val; };   // 重载comp_val,没有argument时读取，有argument时写入
        void comp_val( int nval ) { _val = nval;};

        bool operator() ( int _value ) const { return _value < _val; };

    private:
        int _val;
};

int main()
{
    const unsigned int size = 10;
    int arr[size];
    for ( unsigned int i = 0; i<size; i++ ) {
        arr[i] = 2*i;
    }

    int comp_ref = 20;
    LessThan lt(comp_ref);

    for ( unsigned int i = 0; i < size; i++ ) {
        if ( lt(arr[i]) )
            cout << arr[i] << ", ";
        cout << endl;
    }

}

