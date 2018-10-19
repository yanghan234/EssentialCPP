#include <iostream>
#include <vector>
using namespace std;

vector<int> sort(vector<int> arr, unsigned by=0);
void swap_by_value(int a, int b);
void swap_by_reference(int &a, int &b);
void swap_by_pointer(int *a, int *b);
void output_results(vector<int> a, vector<int> b);

int main()
{
    const int size = 8;
    int a[size] = {1,3,2,4,5,7,6,8};
    vector<int> arr(a,a+size);
    vector<int> arr0(size),arr1(size),arr2(size);

    arr0 = sort(arr,0);
    output_results(arr,arr0);
    arr1 = sort(arr,1);
    output_results(arr,arr1);
    arr2 = sort(arr,2);
    output_results(arr,arr2);
}

vector<int> sort(vector<int> arr, unsigned by)
{
    if (by == 0){
        cout << "Sorting by value" << endl;
    } else if (by == 1){
        cout << "Sorting by reference" << endl;
    } else if (by == 2){
        cout << "Sorting by pointer" << endl;
    }
    for (unsigned i = 0; i < arr.size()-1; i++){
        for (unsigned j = i+1; j < arr.size(); j++){
            if (arr[i] > arr[j]){
                if ( by == 0 ){
                    swap_by_value(arr[i],arr[j]);
                }else if ( by == 1 ){
                    swap_by_reference(arr[i],arr[j]);
                }else if ( by == 2 ){
                    swap_by_pointer(&arr[i],&arr[j]);
                }
            }
        }
    }
    return arr;
}

void swap_by_value(int a, int b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void swap_by_reference(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void swap_by_pointer(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void output_results(vector<int> a, vector<int> b)
{
    cout << "Before sorting: ";
    for (unsigned i=0; i<a.size(); i++) cout << a[i] << " ";
    cout << endl;
    cout << "After sorting:  ";
    for (unsigned i=0; i<b.size(); i++) cout << b[i] << " ";
    cout << endl;
}
