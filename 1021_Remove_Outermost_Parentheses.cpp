//https://leetcode.com/problems/remove-outermost-parentheses/

#include <iostream>
#include <vector>

using namespace std;

string removeOuterParentheses(string S) {
    string result;
    int open=0, close=0;
    int pos=0;
    
    for(int i=0; i<S.size(); i++) {
        
        if( S[i] == '(' ) open++;
        else if( S[i] == ')' ) close++;
        
        if( open == close ) {
            result.erase(pos,1);
            pos = result.size();
        }
        else {
            result += S[i];
        }
    }
    
    return result;
}

int main() {

    cout<< removeOuterParentheses("(()())(())");


    return 1;
}

/*
Input: "(()())(())"
Output: "()()()"
*/