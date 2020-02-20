/* 1155_Number_of_Dice_Rolls_With_Target_Sum */
//https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
int numRollsToTarget(int d, int f, int target, T& dp, int res = 0) {
  if (d == 0 || target <= 0) return d == target;
  if (dp[d][target]) 
    return dp[d][target] - 1;

  for (auto i = 1; i <= f; ++i)
    res = (res + numRollsToTarget(d - 1, f, target - i, dp)) % 1000000007;

  dp[d][target] = res + 1;
  return res;
}


int main() {

    int dp[31][1001] = {};
    cout << numRollsToTarget(2, 6, 7, dp);

    return 0;
}