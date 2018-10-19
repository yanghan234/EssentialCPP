/*
 * Han Yang, Aug-29-2018
 * STL, map and set
 */
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    ifstream infile("ex3.1.txt");
    map<string,int> mymap;
    map<string,int>::iterator it;
    set<string> exclude_set = {"a","an","or","the","and","but"};
    string line;

    while ( infile >> line )
    {
        if ( !exclude_set.count( line ) )
            mymap[line]++;
    }

    for ( it = mymap.begin(); it != mymap.end(); it++ )
        cout << "key: " <<  it->first << " value: " << it->second << endl;


}

