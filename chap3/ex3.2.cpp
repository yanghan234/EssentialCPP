/*
 * Oct-19-2018
 * Just like exercise 3.1, read in text and store them in vector.
 * sort the text in the vector by the length.
 */
#include <set>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void sort( vector<string>::iterator first, vector<string>::iterator last, bool (*pred)(string &, string &));
void swap(string &a, string &b);
bool compare(string &a, string &b);
template < typename IterType, typename T>
void sort_v2(IterType first, IterType last, bool (*pred)(T&,T&) );

int main()
{
    set<string> exclude_set = {"a","an","or","the","and","but"};
    ifstream inFile("ex3.1.txt");
    string line;
    vector<string> svec;
    vector<string>::iterator it;

    while ( inFile >> line )
        if ( !( exclude_set.count(line) ) )
            svec.push_back(line);

    //sort(svec.begin(),svec.end(),compare);
    //for ( it = svec.begin(); it != svec.end(); it++ )
    //    cout << *it << endl;

    sort_v2(svec.begin(),svec.end(),compare);
    for ( it = svec.begin(); it != svec.end(); it++ )
        cout << *it << endl;

}

void sort( vector<string>::iterator first, vector<string>::iterator last, bool (*pred) (string &,string &) )
{
    vector<string>::iterator it1,it2;
    for ( it1 = first; it1 != last-1; it1++ ){
        for ( it2 = it1 + 1; it2 != last; it2++ ){
            if ( ! pred( *it1, *it2) ){
                swap( *it1, *it2 );
            }
        }
    }
}

void swap(string &a, string &b)
{
    string c;
    c = a;
    a = b;
    b = c;
}

bool compare(string &a, string &b)
{
    if ( a.size() <= b.size() ){
        return true;
    } else {
        return false;
    }
}

template < typename IterType, typename T>
void sort_v2(IterType first, IterType last, bool (*pred)(T&,T&) )
{
    IterType it1, it2;
    for ( it1 = first; it1 != last-1; it1++ ){
        for ( it2 = it1 + 1; it2 != last; it2++ ){
            if ( !pred(*it1, *it2) ){
                swap(*it1,*it2);
            }
        }
    }
}


