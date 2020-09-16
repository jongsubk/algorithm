//https://leetcode.com/problems/di-string-match/
// Decrease, Increase <-> left, right

#include <iostream>
#include <vector>
using namespace std;

vector<int> diStringMatch(string S) {
    vector<int> v;
    int left = 0;
    int right = S.size();
    
    for(int i=0; i<S.size(); i++) {
        if( S[i] == 'I') {
            v.push_back(left++);
        }
        else if( S[i] == 'D' ) {
            v.push_back(right--);
        }
    }
    v.push_back(left);

    return v;
}

int main() {
    diStringMatch("IDID");
    
    return 0;
}
