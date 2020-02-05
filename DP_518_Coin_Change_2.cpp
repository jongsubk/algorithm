/* DP_518_Coin_Change_2 */
// https://leetcode.com/problems/coin-change-2

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

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

int main() {

    vector<int> v = { 2,3 };
    cout << change(5, v);

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