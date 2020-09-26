//300. Longest Increasing Subsequence
//https://leetcode.com/problems/longest-increasing-subsequence/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1);
        
        for(int i=1; i<N; i++) {
            for(int j=0; j<i; j++) {
                if( nums[j] < nums[i] ) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        
        int result=0;
        for(int i : dp) {
            if( i > result ) {
                result = i;
            }
        }
        return result;
        
    }
};
