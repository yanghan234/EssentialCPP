/*
 * Oct-19-2018
 * Using a set
 */
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    set<string> word_exclusion;
    map<string,int> words;

    string s[] = {"a","ab","sfsa","a"};
    vector<string> svec(s,s+4);
    vector<string>::const_iterator sit = svec.begin();

    for ( ; sit != svec.end(); sit++ ) {
        if ( word_exclusion.count(*sit) ) continue;
        words[ *sit ]++;
    }

    map<string,int>::const_iterator mit = words.begin();
    for ( ; mit != words.end(); mit++ ) {
        cout << " key: " << mit->first
            << " value: " << mit->second << endl;
    }

}
