/*
 * Han Yang, Oct-13-2018
 * In this file, we explore the basic properties of containers in STL
 * 
 * Be careful! This file cannot be run.
 */

// 3 squential container
#include <vector>
#include <list>
#include <deque>

#include <iostream>
#include <string>
using namespace std;


void create_container()
{
    // create empty containers
    list<string> slist;
    vector<string> svec;

    // create containers with preset sizes;
    list<int> ilist(10);
    vector<int> ivec(10);

    // create containers with preset sizes and initialization
    list<int> iilist(10,1);
    vector<string> ssvec(10,"hello");

    // create containers with a pair of iterator
    int a[8] = {1,2,3,4,5,6,7,8};
    vector<int> vec(a,a+8);

    // create a container from an existing container
    vector<int> iiivec(vec);

}

void add_or_delte_in_container()
{
    // using push_back, pop_back, or push_front, pop_front
    deque<int> a_line;
    int ival;
    while ( cin >> ival )
    {
        // add val to the end of the deque
        a_line.push_back(ival);

        // fetch first value in the deque
        int curr_val = a_line.front();

        // delete first value
        a_line.pop_front();
    }
}

void insert_to_container()
{
    // iterator insert( iterator position, elemType value )
    // add value to the container at position
    // return : the iterator to the inserted value
    list<int> ilist;
    int ival = 10;

    list<int>::iterator it = ilist.begin();
    while ( it != ilist.end() ){
        if ( *it >= ival ){
            ilist.insert(it, ival);
            break;
        }
        it++;
    }
    if ( it == ilist.end() ) ilist.push_back(ival);
}

void erase_container( )
{
    // iterator erase( iterator position )
    // delete the element at position
    //
    // iterator erase( iterator first, iterator last )
    // delete the elements between first and last
    list<int> ilist;
    list<int>::iterator first = ilist.begin();
    list<int>::iterator last = ilist.end();
    ilist.erase(first);
    ilist.erase(first,last);
}



