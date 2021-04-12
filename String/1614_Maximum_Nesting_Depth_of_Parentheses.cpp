//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

#include <iostream>

using namespace std;

int maxDepth(string s) {
    int depth=0, max_depth=0;
    
    for(char c : s) {
        if(c =='(') depth++;
        else if(c ==')') depth--;
        
        if( max_depth < depth) max_depth=depth;
    }
    
    return max_depth;
}

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    cout << maxDepth(s);
    
    return 1;
}