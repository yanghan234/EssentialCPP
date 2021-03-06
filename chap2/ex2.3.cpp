/*
 * Han Yang, Aug-29-2018
 * Pentagonal sequence:
 * P(n) = n(3n-1)/2
 */
#include <iostream>
#include <vector>
using namespace std;

void pen_seq(vector<int> &seq, unsigned size);
inline bool isQualified(vector<int> seq, unsigned size, const unsigned MAXSIZE);
void output_results(vector<int> seq, string dtype);

int main()
{
    unsigned size = 10;
    vector<int> seq;
    pen_seq(seq,size);
    output_results(seq,"int");
}

void pen_seq(vector<int> &seq, unsigned size)
{
    const unsigned MAXSIZE = 10000;
    if (isQualified(seq,size,MAXSIZE)){
        for (unsigned i=0;i<size;i++){
            seq.push_back(int((i+1)*(3*(i+1)-1)/2));
        }
    }
}

inline bool isQualified(vector<int> seq, unsigned size, const unsigned MAXSIZE)
{
    if (size > MAXSIZE){
        cout << "Cannot handle such a large size." << endl;
        return false;
    }else if (size <= seq.size()){
        cout << "Already computed!" << endl;
        return false;
    }else{return true;}
}

void output_results(vector<int> seq, string dtype)
{
    cout << "Pentagonal sequence is: " << endl;
    for ( unsigned i=0;i<seq.size();i++) cout << seq[i] << " ";
    cout << endl;
    cout << "Data type: " << dtype << endl;
}
