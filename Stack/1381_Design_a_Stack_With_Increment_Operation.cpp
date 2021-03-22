//https://leetcode.com/problems/design-a-stack-with-increment-operation/submissions/

#include <iostream>
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


int main()
{
    CustomStack st(3);
    st.push(1);
    st.push(2);
    cout << st.pop();
}