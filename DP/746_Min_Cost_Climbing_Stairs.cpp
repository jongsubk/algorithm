//https://leetcode.com/problems/min-cost-climbing-stairs/

#include <iostream>
#include <vector>
using namespace std;

#if 0
//brute force. recursive. => time out
int helper(vector<int>& cost, int i) {
    
    //stop condition
    if( i >= cost.size() ) return 0;
    
    return cost[i] + min( helper(cost, i+1), helper(cost, i+2) );
    
}

int minCostClimbingStairs(vector<int>& cost) {
    
    return min( helper(cost, 0), helper(cost, 1) );
}
#endif

//Using dynamic programming, divide and conquer
int minCostClimbingStairs(vector<int>& cost) {
    
    vector<int> dp( cost.size()+1 );  //estimated cost vector
    dp[0] = cost[0];
    dp[1] = cost[1];
    
    for(int i=2; i<cost.size(); i++) {
        dp[i] = cost[i] + min(dp[i-2], dp[i-1]);
    }
    
    return min(dp[cost.size()-1], dp[cost.size()-2]);
}

int main() {
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    cout << minCostClimbingStairs(cost);

    return 1;
}

/* Sample
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
*/