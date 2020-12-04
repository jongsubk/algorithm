//https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//using vector as stack
/*bool isValid(string s) {
    vector<char> v;
    
    for(char c : s) {
        if( v.empty() ) {
            v.push_back(c);
            continue;
        }
        
        if( (v.back()=='(' && c==')') || (v.back()=='{' && c=='}') || (v.back()=='[' && c==']') ) {
            v.pop_back();
        } else {
            v.push_back(c);
        }
    }
    return v.empty();
}
*/

//using stack
bool isValid(string s) {
    stack<char> v;
    
    for(char c : s) {
        if( v.empty() ) {
            v.push(c);
            continue;
        }
        
        if( (v.top()=='(' && c==')') || (v.top()=='{' && c=='}') || (v.top()=='[' && c==']') ) {
            v.pop();
        } else {
            v.push(c);
        }
    }
    return v.empty();
}

int main() {

    cout << isValid("()");

    return 1;
}


/*
Input: s = "()[]{}"
Output: true

Input: s = "([)]"
Output: false
*/