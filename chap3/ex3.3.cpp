/*
 * Oct-19-2018
 * Create a map to hold children's name, where keys and values in the map are surnames and given names.
 */
#include <map>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;


int main()
{
    typedef vector<string> vstring;
    string firstName, lastName;
    map<string,vstring> names;
    ifstream inFile("ex3.3.txt");

    while ( inFile >> firstName >> lastName ){
        names[lastName] = firstName;
    }


    map<string,string>::iterator it;
    for ( it = names.begin(); it != names.end(); it++ ){
        lastName = it->first;
        cout << lastName << ", " << names[lastName] << endl;
    }



}

string search_by_last( map<string,string> &names, string &lastName )
{
    if ( names.count( lastName ) ){
        return names[ lastName ];
    } else {
        return "\0";
    }
}
