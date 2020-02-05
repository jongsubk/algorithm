/* DP_518_Coin_Change_2 */
// https://leetcode.com/problems/coin-change-2

/* 322_Coin_Change */
//https://leetcode.com/problems/coin-change/

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

/* DP_518_Coin_Change_2 */
//Return the number of combinations that make up that amount.
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount+1, 0);
    dp[0] = 1;

    for(int coin : coins) {
        for(int i=coin; i<=amount; i++) {
            dp[i] += dp[i-coin];
        }
    }
    return dp[amount];
}

/* 322_Coin_Change */
//Return the fewest number of coins that you need to make up that amount.
int coinChange(vector<int>& coins, int amount) 
{
    vector<int> dp(amount + 1, -1);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; ++i)
        for (int coin : coins)
            if (i - coin >= 0 && dp[i - coin] != -1)
                dp[i] = dp[i] > 0 ? min(dp[i], dp[i - coin] + 1) : dp[i - coin] + 1;
    
    return dp[amount];
}

int main() {

    vector<int> v = { 1,2,5 };
    cout << "DP_518_Coin_Change_2: " << change(5, v);
    cout << endl;

    cout << "322_Coin_Change: " << coinChange(v, 11);

    return 0;
}

/* tried recusion
int change(int amount, vector<int>& coins) {
    if( amount == 0 ) { return 1; }
    else if( amount <0 ) { return 0; }

    int res = 0;    
    for(int i=0; i<coins.size(); i++) {
        res += change( amount-coins[i], coins);
    }  
    return res;
}
*/