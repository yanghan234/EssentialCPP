/*
 * Han Yang, Oct-13-2018
 * How to design generic algorithm
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> less_than_10( vector<int> &vec );
vector<int> less_than( vector<int> &vec, const int &val );
vector<int> filter( vector<int> &vec, const int &val, bool (*pred) (int,int) );
bool less_than(int i, int j);
bool greater_than(int i, int j);
template < typename IteratorType >
void display( IteratorType begin, IteratorType end);

int main()
{
    unsigned size = 8;
    int arr[size];
    // initializing
    for ( unsigned i = 0; i < size; i++ ) arr[i] = 3*i;
    vector<int> vec(arr,arr+size);

    vector<int> nvec = less_than_10(vec);

    display(nvec.begin(), nvec.end());

    nvec.erase(nvec.begin(),nvec.end());

    nvec = less_than(vec,15);

    display(nvec.begin(),nvec.end());

    nvec.erase(nvec.begin(), nvec.end());
    nvec = filter(vec,15,less_than);
    display(nvec.begin(), nvec.end());

    nvec.erase(nvec.begin(), nvec.end());
    nvec = filter(vec,15,greater_than);
    display(nvec.begin(), nvec.end());
}

// Given a vector of integers, return another vector of all integers smaller than 10
vector<int> less_than_10( vector<int> &vec )
{
    vector<int> nvec;
    for ( unsigned i = 0; i < vec.size(); i++ ) {
        if ( vec[i] < 10 )
            nvec.push_back( vec[i] );
    }
    return nvec;
}

// The function less_than_10 is not good enough, if we want to get the numbers smaller than 11,
// we have to define another function, e.g.
vector<int> less_than( vector<int> &vec, const int &val )
{
    vector<int> nvec;
    for ( unsigned i = 0; i < vec.size(); i++ ) {
        if ( vec[i] < val )
            nvec.push_back(vec[i]);
    }
    return nvec;
}

// The function less_than is still not generic enough, what if we want to get results larger than
// a certain value? So, we have to make it more generic that we can specify the condition we want.
vector<int> filter( vector<int> &vec, const int &val, bool (*pred) (int,int) )
{
    vector<int> nvec;
    for ( unsigned i = 0; i < vec.size(); i++ ) {
        if ( pred(vec[i], val) )
            nvec.push_back( vec[i] );
    }
    return nvec;
}

// define comparison functions to be used in filter
bool less_than(int i, int j)
{
    if ( i < j ) { return true;}
    else { return false;}
}
bool greater_than(int i, int j)
{
    if ( i > j ) { return true; }
    else { return false; }
}

// To display the container, e.g. vector
template < typename IteratorType >
void display( IteratorType begin, IteratorType end)
{
    for ( ; begin < end; begin++ )
        cout << *begin << ",";
    cout << endl;
}
