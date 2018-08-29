/*
 * Han Yang, Aug-29-2018
 * MyMax() function that provides overloading feature
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int     MyMax(           int, int       );
float   MyMax(         float, float     );
string  MyMax(        string, string    );
int     MyMax(   vector<int>            );
float   MyMax( vector<float>            );
string  MyMax(vector<string>            );
int     MyMax(         int *, unsigned  );
float   MyMax(       float *, unsigned  );
string  MyMax(      string *, unsigned  );

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

int     MyMax(int a, int b)
{
    return a>b?a:b;
}

float   MyMax(float a, float b)
{
    return a>b?a:b;
}

string  MyMax(string a, string b)
{
    return a>b?a:b;
}

int     MyMax(vector<int> a)
{
    int tmp = 0;
    for (unsigned i=0; i<a.size(); i++){
        tmp = MyMax(tmp,a[i]);
    }
    return tmp;
}

float   MyMax(vector<float> a)
{
    float tmp = 0.0;
    for (unsigned i=0; i<a.size(); i++){
        tmp = MyMax(tmp,a[i]);
    }
    return tmp;
}

string  MyMax(vector<string> a)
{
    string tmp="";
    for (unsigned i=0; i<a.size(); i++){
        tmp = MyMax(tmp,a[i]);
    }
    return tmp;
}

int     MyMax(        int *a, unsigned size )
{
    int tmp = 0;
    for (unsigned i=0;i<size;i++) tmp = MyMax(tmp,a[i]);
    return tmp;
}

float   MyMax(      float *a, unsigned size )
{
    float tmp = 0.0;
    for (unsigned i=0;i<size;i++) tmp = MyMax(tmp,a[i]);
    return tmp;
}

string  MyMax(     string *a, unsigned size )
{
    string tmp = "";
    for (unsigned i=0;i<size;i++) tmp = MyMax(tmp,a[i]);
    return tmp;
}
