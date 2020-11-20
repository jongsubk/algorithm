//https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canMakeArithmeticProgression(vector<int>& arr) {
    //1. sort array in asending
    //2. calculate difference in traversing
    //  2.1 return false if difference is not the same with previous
    //3. return true;
    
    sort(arr.begin(), arr.end());
    
    int diff = arr[1]-arr[0];
    
    for( int i=1; i< arr.size(); i++) {
        if( (arr[i]-arr[i-1]) != diff ) {
            return false;
        }
    }
    
    return true;
}

int main() {

    vector<int> v = { 4, 2, 8, 6, 7 };
    cout << canMakeArithmeticProgression(v);

}