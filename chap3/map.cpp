/*
 * Oct-19-2018
 * Using a map
 */
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
    map<string,int> words;
    words[ "vermeer" ] = 1;

    string s[] = {"a","ab","sfsa","a"};
    vector<string> svec(s,s+4);
    vector<string>::const_iterator sit = svec.begin();

    for ( ; sit != svec.end(); sit++ ){
        words[ *sit ] ++;
    }

    map<string,int>::iterator it = words.begin();
    for ( ; it != words.end(); it++ ){
        // Using iterator->first and iterator->second to get keys and values in a map
        cout << " key: " << it->first
            << " value: " << it->second << endl;
    }

    // Check if a key in a map
    // Method 1:
    // This method has a problem. If the key was not in the map initially, this key would be added to the map.
    int count = 0;
    if ( !( count = words["vermeer"] ) ){
        cout << count << endl;
    }

    // Method 2:
    // Using find() function of map class
    // Return value type:
    //          pair, if the key is in the map
    //          end(), if the key is not int the map
    it = words.find("vermeer");
    if ( it != words.end() ){
        count = it->second;
    }

    // Method 3：
    // Using count() function of map class
    // Return value:
    //          number of the key
    if ( words.count( "vermeer" ) )
        count = words[ "vermeer" ];

}

