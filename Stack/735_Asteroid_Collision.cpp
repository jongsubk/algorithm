#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for(int i=0; i < asteroids.size(); i++) {
        int data = asteroids[i];
        if(st.empty() || data>0) {
            st.push(data);
            continue;
        }      
        
        if( st.top() >0 && data <0 ) {
            int compare = st.top() - (-data);
            if( compare >0 ) {
                
            } else if( compare ==0) {
                st.pop();
                
            } else {
                st.pop();
                i--;
            }
        } else {
            st.push(data);
        }
    }
    
    //stack? vector? ??
    vector<int> v;
    while( !st.empty() ) {
        v.insert(v.begin(), st.top());
        st.pop();
    }
    
    return v;
}

int main() {

    //vector<int> v = { -1, 1, 1, -2, 4};
    vector<int> v = { 5, 10, -5};
    
    vector<int> res = asteroidCollision(v);

    for(int a : res) {
        cout << a << ",";
    }

    return 1;
}