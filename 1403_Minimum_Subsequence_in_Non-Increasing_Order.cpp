//https://leetcode.com/problems/minimum-subsequence-in-non-increasing-order/
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


vector<int> minSubsequence(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<>());
    
    vector<int> ret;

    int sum = accumulate(nums.begin(), nums.end(), 0);
    int subsum=0;
                            
    for(int i=0; i< nums.size(); i++) {
        subsum += nums[i];
        sum -= nums[i];
        
        ret.push_back(nums[i]);
        if( subsum > sum ) {
            return ret;
        }
    }
    
    return ret;
}


int main() {

    vector<int> v = { 2,3,4,9,10,9};

    vector<int> result = minSubsequence(v);

    for(int value : result){
        cout << value << " ";
    }

}