//https://leetcode.com/problems/count-good-triplets/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int result=0;
    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            for(int k=j+1; k<arr.size(); k++) {
                if( abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c ) {
                    result++;
                }
            }
        }
    }
    
    return result;
}


int main() {
    vector<int> v = { 3,0,1,1,9,7 };
    cout << countGoodTriplets( v, 7,2,3);

    return 0;
}