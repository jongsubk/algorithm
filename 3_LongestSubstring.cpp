/* 3. Longest Substring Without Repeating Characters */
//★★★★

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int length=0;
    int fp=0, lp=0;
    vector<char> v;
    
    while( lp < s.size() && fp < s.size() ) {
        
        if( find(v.begin(), v.end(), s[lp]) == v.end() ) {  //not found
            v.push_back( s[lp] );
            lp++;
            length = max(length, lp-fp);
            
        } else {
            vector<char>::iterator it = find(v.begin(), v.end(), s[fp]);
            v.erase( it );
            fp++;
        }
        
    }
    return length;
}

int main() {

    string s("abcabcccdedfg");
    cout << lengthOfLongestSubstring(s);

    return 0;
}
//https://leetcode.com/problems/longest-substring-without-repeating-characters/
/* end of - 3. Longest Substring Without Repeating Characters */