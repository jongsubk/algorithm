/* 347. Top K Frequent Elements */
//https://leetcode.com/problems/top-k-frequent-elements/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    
    for(int num: nums) {
        map[num]++;
    }        

    vector<pair<int,int>> v; 
    for(auto it = map.begin(); it != map.end(); it++){
        v.push_back(make_pair(it->second, it->first));
    }
    
    sort(v.begin(), v.end());
            
    vector<int> res;
    for(int i=0;i<k; i++) {
        res.push_back( v.back().second );
        v.pop_back();
    }
    
    return res;
}



int main() {
    vector<int> v = { 1,1,1, 2,2,3};
    vector<int> result = topKFrequent(v,2);

    for(int i : result) {
        cout << i << ", ";
    }
    return 0;
}