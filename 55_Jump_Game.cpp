/* 55_Jump_Game */
// https://leetcode.com/problems/jump-game/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Approach 1: Backtracking */
bool canJumpFromPosition(int position, vector<int>& nums) {
    if (position == nums.size() - 1) {
        return true;
    }

    int furthestJump = min(position + nums[position], (int)(nums.size()-1) );
    for (int nextPosition = position + 1; nextPosition <= furthestJump; nextPosition++) {
        if (canJumpFromPosition(nextPosition, nums)) {
            return true;
        }
    }

    return false;
}
bool canJump(vector<int>& nums) {
    return canJumpFromPosition(0, nums);
}


/* //Approach 4: Greedy
bool canJump(vector<int>& nums) {
    int lastPos = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (i + nums[i] >= lastPos) {
            lastPos = i;
        }
    }
    return lastPos == 0;
}
*/

int main()
{
    vector<int> v = { 3,2,1,0,4 };
    
    cout << canJump(v);

    return 1;
}