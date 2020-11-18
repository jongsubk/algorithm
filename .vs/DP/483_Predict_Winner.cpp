#include <iostream>
#include <vector>

using namespace std;
/*
bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n)); // use to keep the score gap between player1 and player2
    
    for (int i = 0; i < n; i++) dp[i][i] = nums[i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j+i < n; j++) {
            dp[j][j+i] = max(nums[j+i]-dp[j][j+i-1], nums[j]-dp[j+1][j+i]);
        }
    }
    return dp[0][n-1] >= 0; // player1 get more score points than player2
}
*/

int dp[20][20][2];
int helper(vector<int>& nums, int s, int e, int player) {
    if( s>e ) 
        return 0;

    if( dp[s][e][player-1] != 0 ) {
        return dp[s][e][player-1];
    }

    int ret=0;
    if( player ==1) {
        ret = dp[s][e][player-1] = max( nums[s] + helper(nums, s+1,e,2), nums[e] + helper(nums, s,e-1,2));        
    }
    else {
        ret = dp[s][e][player-1] = min( helper(nums, s+1,e,1), helper(nums, s,e-1,1));
    }

    return ret;
}

bool PredictTheWinner(vector<int>& nums) {
    int sum=0;
    for(int value : nums)
        sum += value;

    int player1 = helper(nums, 0, nums.size()-1, 1); //player1(1) player2(2)

    return ( player1 >= (sum-player1) );
}


int main() {
    vector<int> v = {1, 5, 233, 7};

    cout << PredictTheWinner(v);

    return 1;
}