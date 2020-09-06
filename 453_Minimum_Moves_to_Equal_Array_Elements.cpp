//https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int sum=0;
        int min = nums[0];
        for( int num : nums ) {
            sum += num - min;
        }
        
        return sum;
        
        // Ex.[1,3,8]
        // => [2,4,8] [3,5,8], [4,6,8], [5,7,8], [6,8,8], [7,9,8], [8,9,9], [9,10,9], [10,10,10]
    }
};

int main() {

    Solution sol;
    vector<int> v = { 1,3,8};
    cout << sol.minMoves(v);

    return 0;
}