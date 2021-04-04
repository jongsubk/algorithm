//https://leetcode.com/problems/design-a-stack-with-increment-operation/submissions/

#include <iostream>
#include <Vector>
#include <algorithm>
using namespace std;


class CustomStack {
public:
    int top = 0;
    int _maxSize;
    int* data = NULL;

    CustomStack(int maxSize) {
        _maxSize = maxSize;
        data = new int[maxSize+1];
    }
    
    void push(int x) {
        if( top < _maxSize ) {
            data[++top] = x;
        }
    }
    
    int pop() {
        if(top == 0)
            return -1;
        
        return data[top--];
    }
    
    void increment(int k, int val) {
        for(int i=1; i<= min(k, _maxSize); i++) {
            data[i] += val;
        }
    }
};


int maxCoins(vector<int>& piles) {
    
    int sum = 0;
    
    sort(piles.begin(), piles.end(), [](int a, int b) {
        return a<b;
    });

    int n = piles.size();
    
    for(int i= n-2; i>= n/3; i-=2) {
        sum += piles[i];
    }
    
    return sum;
}


int main()
{
    //CustomStack st(3);
    //st.push(1);
    //st.push(2);
    //cout << st.pop();

    vector<int> v = { 2,4,5, 7, 8, 9 };
    cout << "maxCoins: " << maxCoins(v);


}