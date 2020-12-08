//https://leetcode.com/problems/score-of-parentheses/

#include <iostream>
#include <stack>
using namespace std;

int scoreOfParentheses(string S) {
    stack<int> s;
    int cur = 0;
    for(char c : S) {
        
        if( c == '(' ) {
            s.push(cur);
            cur = 0;
        }
        else if( c == ')' ) {
            cur += s.top() + max(cur,1);
            s.pop();
        }
    }
    
    return cur;
}

int main() {

    cout << scoreOfParentheses("(()(()))");
    return 1;
}

/*
Input: "(()(()))"
Output: 6
*/