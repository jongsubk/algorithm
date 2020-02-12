/* 46_Permutations */
// ★★★★
//https://leetcode.com/problems/permutations/

#include <iostream>
#include <vector>

using namespace std;

void permute_helper(vector<int> nums, int i, vector<vector<int>>& perms) {
    //stop condition
    if (i == nums.size()) {
        perms.push_back(nums);
        return;
    }
    
    for (int j = i; j < nums.size(); j++) {
        swap(nums[i], nums[j]);
        permute_helper(nums, i + 1, perms);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> perms;
    permute_helper(nums, 0, perms);
    return perms;
}

int main() 
{
    vector<int> v = {1,2,3};
    vector<vector<int>> perms;

    perms = permute(v);

    return 1;
}