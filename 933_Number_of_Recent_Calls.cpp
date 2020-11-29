//https://leetcode.com/problems/number-of-recent-calls/

#include <iostream>
#include <queue>
using namespace std;


class RecentCounter {

private:
    queue<int> q;

public:
    RecentCounter() {
        
    }
    
    //1. push t value to q
    //2. loop dequeue if dequeue value is less than t-3000
    int ping(int t) {
        q.push(t);
        
        while( q.front() < t-3000 ) {
            q.pop();
        }
        
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

int main() {

    RecentCounter* obj = new RecentCounter();
    cout << obj->ping(1) << ", ";
    cout << obj->ping(3000) << ", ";
    cout << obj->ping(3002) << ", ";
 
    return 1;
}