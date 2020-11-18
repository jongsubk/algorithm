#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> v = heights;
        
        sort(v.begin(), v.end());
        
        int result=0;
        
        for(int i=0; i<heights.size(); i++) {
            if( heights[i] != v[i])
                result++;
        }
        
        return result;
    }
};


int main() {

    Solution sol;
    vector<int> v = {1,2,4,5,2};
    cout << sol.heightChecker(v);
}