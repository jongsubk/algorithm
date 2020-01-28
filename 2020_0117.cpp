#include <iostream>
#include <vector>

using namespace std;


void func1(vector<int> a) {
    a.push_back(9);
}

int main()
{
    vector<int> v;
    v.push_back(1);

    func1(v);

    for(int a: v) {
        cout << a << ". ";
    }


    return 1;
}