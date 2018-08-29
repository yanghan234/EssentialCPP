/*
 * Han Yang, Aug-29-2018
 * local static object, pentagonal sequence as an example.
 */
#include <iostream>
#include <vector>
using namespace std;

vector<int> * pen_seq(unsigned size);
inline bool isQualified(vector<int> seq, unsigned size, const unsigned MAXSIZE);
int find_value(vector<int> *seq, unsigned pos);
void output_results(vector<int> *seq);

int main()
{
    vector<int> *seq;
    seq = pen_seq(5);
    cout << find_value(seq,5) << endl;
    output_results(seq);
    seq = pen_seq(10);
    output_results(seq);
    seq = pen_seq(8);
    output_results(seq);

}

vector<int> * pen_seq(unsigned size)
{
    const unsigned MAXSIZE = 10000;
    static vector<int> seq;
    if (isQualified(seq,size,MAXSIZE)){
        for (unsigned i=seq.size();i<size;i++){
            seq.push_back(int((i+1)*(3*(i+1)-1)/2));
            }
    }
    return &seq;
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

void output_results(vector<int> *seq)
{
    cout << "Pentagonal sequence is: " << endl;
    for ( unsigned i=0;i<(*seq).size();i++) cout << (*seq)[i] << " ";
    cout << endl;
}

int find_value(vector<int> *seq, unsigned pos)
{
    if (pos >= (*seq).size()){
        cout << "vector overflow" << endl;
        return -1;
    }else{
        return (*seq)[pos];
    }
}
