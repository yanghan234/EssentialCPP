#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    std::istream_iterator<int> is(std::cin);
    std::istream_iterator<int> eof;
    std::ostream_iterator<int> os(std::cout);

    vector<int> ivec;
    std::copy(is, eof, std::back_inserter(ivec));

    // Type ctrl+D before this line will be executed.
    std::copy(ivec.begin(),ivec.end(),os);

}
