//DP_1299_Replace_Elements_with_Greatest_Element_on_Right_Side
//https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

#include <iostream>
#include <vector>

using namespace std;


// brute force method
//time compleaxity O(n^2) , space complexity O(n)
//Runtime: 432 ms, faster than 14.87%
//Memory Usage: 10.7 MB, less than 100.00%
/*
vector<int> replaceElements(vector<int>& arr) {
    
    for(int i=0; i<arr.size(); i++) {
        int max=-1;
        for(int j=i+1; j<arr.size(); j++) {
            max = (max < arr[j] ? arr[j] : max);
        }
        arr[i] = max;
    }  
    return arr;
}
*/

//DP
//Runtime: 52 ms, faster than 78.72%
//Memory Usage: 10.6 MB, less than 100.00%
vector<int> replaceElements(vector<int>& arr) {
    vector<int> dp( arr.size() );
    dp[arr.size() -1] = -1;
        
    for(int i=arr.size()-2; i>=0; i--) {
        dp[i] = max( arr[i+1], dp[i+1] );
    }
    return dp;
}

int main()
{
    vector<int> v = { 17,18,5,4,6,1 };

    vector<int> ret = replaceElements(v);

    for(int i=0; i<v.size(); i++) {
        cout << ret[i] << ", ";
    }

    return 0;
}