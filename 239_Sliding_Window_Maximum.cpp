#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;

    for(int i=0; i< nums.size(); i++) {

        while( !dq.empty() && dq.back() < nums[i] ) { dq.pop_back(); }
        
        dq.push_back(nums[i]);

        if( i >= (k-1) ) {
            ans.push_back( dq.front() );

            if( nums[i-k+1] == dq.front() ) dq.pop_front();
        }
    }

    return ans;
}
    

int main() {

    vector<int> v = { 1,3,-1,-3,5,3,6,7 };
    vector<int> result = maxSlidingWindow(v, 3);

    return 0;
}