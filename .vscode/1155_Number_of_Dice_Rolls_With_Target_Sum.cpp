/* 1155_Number_of_Dice_Rolls_With_Target_Sum */
//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
#include <iostream>
#include <vector>
using namespace std;

//Brute Force Recursive method -> timeout
//time complexity O(f^d), space complexity O(d for stack)
/*
template<typename T>
int numRollsToTarget(int d, int f, int target, T& dp, int res = 0) {
  if (d == 0 || target <= 0) return d == target;

  for (auto i = 1; i <= f; ++i)
    res = (res + numRollsToTarget(d - 1, f, target - i, dp)) % 1000000007;

  return res;
}
*/

//Dynamic Programming method -> time OK
//time complexity O(d*f*target), space complexity O(d*target)
vector<vector<int>> dp= { 31, vector<int>(1001,1) };
//Return the number of possible ways to roll the dice so the sum of the face up numbers equals target
int numRollsToTarget(int d, int f, int target, int res=0) {
    //stop condition
    if( d==0 || target<=0 ) { return d==target; }
        
    if( dp[d][target] !=1 ) return dp[d][target];
    
    for(int i=1; i<=f; i++) {
        res = (res + numRollsToTarget(d-1, f, target-i))% 1000000007;
    }
    
    dp[d][target] = res;
        
    return res;
}

int main() {

    cout << numRollsToTarget(2, 6, 7);

    return 0;
}