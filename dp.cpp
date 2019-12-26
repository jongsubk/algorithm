#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/* 309. Best Time to Buy and Sell Stock with Cooldown */
int maxProfit(vector<int>& prices) {
    
    int n = prices.size();
    if( n < 2 ) return 0;
    
    vector<int> buy(n);  // buy 상태인 i day에서의 최대 수익
    vector<int> sell(n); // sell 상태인 i day에서의 최대 수익 
    buy[0] = -prices[0];
    
    for(int i=1; i<n; i++) {
        buy[i] = max(buy[i-1], (i>1 ? sell[i-2] : 0) -prices[i]); // max(buy상태를 유지하거나, buy한다)
        sell[i] = max(sell[i-1], buy[i-1] +prices[i]);
    }
    
    return sell[n-1];
}

int main() {

    vector<int> v = { 1,2,3,0,2 };
    cout << maxProfit(v);

    return 0;
}
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
/* end of - 309. Best Time to Buy and Sell Stock with Cooldown */