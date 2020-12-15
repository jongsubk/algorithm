//https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


string minRemoveToMakeValid(string s) {
    stack<int> stk;

    for(int i=0; i<s.size(); i++) {
        if( s[i] == '(' ) {
            stk.push(i);
        }else if ( s[i] == ')') {
            if( stk.empty() ) {
                s[i] = '*';
            }
            else {
                stk.pop();
            }
        }
    }
        
    while( !stk.empty() ) {
        s[ stk.top() ] = '*';
        stk.pop();
    }
    
    s.erase( remove(s.begin(), s.end(), '*'), s.end());
    
    return s;
}


int main() {

    cout << minRemoveToMakeValid("(a(b(c)d)");

    return 1;
}