/*
 * Han Yang, Aug-29-2018
 * Pentagonal sequence:
 * P(n) = n(3n-1)/2
 */
#include <iostream>
#include <vector>
using namespace std;

bool pen_seq(vector<int> &seq, unsigned size);
void output_results(vector<int> seq, string dtype);

int main()
{
    unsigned size = 8;
    vector<int> seq;
    pen_seq(seq,size);
    output_results(seq,"int");
}

bool pen_seq(vector<int> &seq, unsigned size)
{
    const unsigned MAXSIZE = 10000;
    if (size > MAXSIZE){
        cout << "Size requested is too large" << endl;
        return false;
    }else{
        for (unsigned i=0;i<size;i++){
            seq.push_back(int((i+1)*(3*(i+1)-1)/2));
        }
        return true;
    }
}

void output_results(vector<int> seq, string dtype)
{
    cout << "Pentagonal sequence is: " << endl;
    for ( unsigned i=0;i<seq.size();i++) cout << seq[i] << " ";
    cout << endl;
    cout << "Data type: " << dtype << endl;
}
