/* 42_Trapping_Rain_Water */
//https://leetcode.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Approach 1: Brute Force method
#if 0
int trap(vector<int>& height) {
    int ans=0;
    
    for(int i=0; i<height.size(); i++) {
        int max_left=0, max_right=0;
        
        for(int j=i-1; j>=0; j--) {
            max_left = max(max_left, height[j]);
        }
        
        for(int j=i+1; j<height.size(); j++) {
            max_right = max(max_right, height[j]);
        }
        
        int temp = min(max_left, max_right);
        if( temp > height[i] ) {
            ans += temp - height[i];
        }
    }
    return ans;
}
#endif


/* Approach 2: Dynamic Programming */
// store DP and iterate 2 time from left and right.
#if 0
int trap(vector<int>& height)
{
    if(height == null)
        return 0;

    int ans = 0;
    int size = height.size();
    vector<int> left_max(size), right_max(size);

    left_max[0] = height[0];
    for (int i = 1; i < size; i++) {
        left_max[i] = max(height[i], left_max[i - 1]);
    }

    right_max[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--) {
        right_max[i] = max(height[i], right_max[i + 1]);
    }

    for (int i = 1; i < size - 1; i++) {
        ans += min(left_max[i], right_max[i]) - height[i];
    }
    return ans;
}
#endif

/* Approach 3: Using stacks */
int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}


/* Approach 4: Using 2 pointers */
//Similar Approach 2, but iterate 1 time using pointers
#if 0
int trap(vector<int>& height)
{
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if( height[left] >= left_max )
                left_max = height[left];
            else
                ans += left_max - height[left];
            ++left;
        }
        else {
            if( height[right] >= right_max )
                right_max = height[right];
            else
                ans += right_max - height[right];
            --right;
        }
    }
    return ans;
}
#endif

int main() {
    vector<int> v = { 4,2,3 };
    cout << trap(v);

    return 1;
}