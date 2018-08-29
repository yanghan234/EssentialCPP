/* 
 * Han Yang, Aug-29-2018
 * local static object
 * As an example, we compute first several elements in Fibonacci sequence.
 */
#include <iostream>
#include <vector>
using namespace std;

void fib_seq(unsigned size);

int main()
{
    fib_seq(5);
    fib_seq(10);
    fib_seq(8);
}

void fib_seq(unsigned size)
{
    static vector<int> FibArr;      // FibArr is the local static object
    if (size < FibArr.size()){
        cout << "Already calculated!" << endl;
    }else{
        cout << "Some elements need to be computed!" << endl;
        for (unsigned i=FibArr.size(); i<size; i++){
            if (i == 0 or i == 1) {
                FibArr.push_back(1);
            }else{
                FibArr.push_back(FibArr[i-1]+FibArr[i-2]);
            }
        }
    }
    cout << "Fibonacci sequence is computed: " << endl;
    for (unsigned i=0; i<size; i++){
        cout << FibArr[i] << " ";
    }
    cout << endl;
}

