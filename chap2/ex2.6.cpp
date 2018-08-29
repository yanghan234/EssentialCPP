/*
 * Han Yang, Aug-29-2018
 * reconstruct functions in ex2.5.cpp by using templates
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T> T MyMax(T,T);
template <typename T> T MyMax(vector<T>);
template <typename T> T MyMax(T *,unsigned);

int main()
{
    // compare two integers;
    int ia = 1, ib = 2;
    cout << MyMax(ia,ib) << endl;
    // compare two floating numbers;
    float fa = 1.0, fb = 2.0;
    cout << MyMax(fa,fb) << endl;
    // compare two strings;
    cout << MyMax("1","212") << endl;
    // int vector;
    vector<int> ivec(3);
    ivec = {1,2,3};
    cout << MyMax(ivec) << endl;
    // float vector;
    vector<float> fvec(3);
    fvec = {1.0,2.0,3.0};
    cout << MyMax(fvec) << endl;
    // string vector;
    vector<string> svec(3);
    svec = {"1","11","111"};
    cout << MyMax(svec) << endl;
    // int array;
    int iarr[3] = {1,2,3};
    cout << MyMax(iarr,3) << endl;
    // float array;
    float farr[3] = {1.0,2.0,3.0};
    cout << MyMax(farr,3) << endl;
    // string array;
    string sarr[3] = {"1","11","111"};
    cout << MyMax(sarr,3) << endl;
}

template <typename T> T MyMax(T a, T b)
{
    return a>b?a:b;
}

template <typename T> T MyMax(vector<T> Tvec)
{
    T tmp = Tvec[0];
    for (unsigned i=0;i<Tvec.size();i++) tmp = MyMax(tmp,Tvec[i]);
    return tmp;
}

template <typename T> T MyMax(T * Tarr, unsigned size)
{
    T tmp = Tarr[0];
    for (unsigned i=0;i<size;i++) tmp = MyMax(tmp,Tarr[i]);
    return tmp;
}
