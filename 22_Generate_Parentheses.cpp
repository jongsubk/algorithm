/* 22_Generate_Parentheses */
// https://leetcode.com/problems/generate-parentheses/
#include <iostream>
#include <vector>
using namespace std;

void helper(string s, int left, int right, vector<string>& result) {
    
    if( !left && !right ) { result.push_back(s); }
    
    if( left ) { helper(s+'(', left-1, right, result); }
    if( left < right ) { helper(s+')', left, right-1, result); }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    helper("" ,n, n, result);
    
    return result;
}


int main()
{
    vector<string> s = generateParenthesis(3);
    
    return 1;
}