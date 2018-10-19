/*
 * Han Yang, Oct-13-2018
 * Given a container, e.g. array, vector, or list, and a value,
 * find if the value in this container. The value could be any data type.
 *
 * Generic programming
 */
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

int * find_v1( vector<int> &vec, const int &val);
template < typename T >
T * find_v2( vector<T> &vec, const T &val);
template < typename T>
T * find_v3( T *arr, int size, const T &val );
template < typename T >
T * find_v4( T *first, T * last, const T &val);
template < typename T >
T * begin( vector<T> &vec );
template < typename T >
T * end( vector<T> &vec );
template < typename IteratorType, typename T >
IteratorType find_v5( IteratorType begin, IteratorType end, const T &val );

int main()
{
    const unsigned size = 8;
    int arr[size] = {1,2,3,4,5,6,7,8};
    vector<int> vec(arr,arr+size);

    int *p1 = find_v1(vec, 2);
    cout << *p1 << endl;

    int *p2 = find_v2(vec, 3);
    cout << *p2 << endl;

    int *p3 = find_v3(&arr[0], size, 2);
    cout << *p3 << endl;

    int *p4 = find_v4(arr, arr+size, 2);
    cout << *p4 << endl;

    vector<int>::iterator iter1 = find_v5( vec.begin(), vec.end(), 2);
    cout << *iter1 << endl;
    int *p5 = find_v5( arr, arr+size, 2 );
    cout << *p5 << endl;
}

// find if a value in a vector
int * find_v1( vector<int> &vec, const int &val )
{
    for ( unsigned int i = 0; i < vec.size(); i++ ){
        if ( vec[i] == val ) { return &vec[i]; }
    }
    return 0;
}

// write a template function so that it deals with multiple data type
template < typename T >
T * find_v2( vector<T> &vec, const T &val )
{
    for ( unsigned int i = 0; i < vec.size(); i++ ){
        if ( vec[i] == val )
            return &vec[i];
    }
    return 0;
}

// find if a value in an array, using starting pointer and size
template < typename T>
T * find_v3( T *arr, int size, const T &val )
{
    if ( !arr || size < 1 ) return 0;
    for ( unsigned i = 0; i < size; i++ ){
        if ( arr[i] == val )
            return &arr[i];
    }
    return 0;
}

// find if a value in an array, using starting and ending pointers
template < typename T >
T * find_v4( T *first, T * last, const T &val )
{
    if ( !first || !last ) return 0;
    for ( unsigned i = 0; first + i < last; i++ ){
        if ( *(first+i) == val )
            return first+i;
    }
    return 0;
}

// In C++, an array shall not be empty, i.e. its size must be at least one.
// A vector, however, can be empty. We have to deal with this feature to avoid
// problems in the functions find_v1 and find_v2.
template < typename T >
T * begin( vector<T> &vec )
{
    return vec.empty() ? 0: &vec[0];
}

template < typename T >
T * end( vector<T> vec )
{
    return vec.empty() ? 0: vec+vec.size();
}

// By using iterator, we upgrade the find function to support vector and array at the same time.
template < typename IteratorType, typename T >
IteratorType find_v5( IteratorType begin, IteratorType end, const T &val )
{
    for ( ; begin < end; begin++ )
        if ( *begin == val )
            return begin;
    return end;
}
