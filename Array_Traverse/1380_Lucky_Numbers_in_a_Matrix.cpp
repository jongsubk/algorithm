//https://leetcode.com/problems/lucky-numbers-in-a-matrix/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> minV;
    
    for(int i=0; i<matrix.size(); i++) {
        minV.push_back( *min_element(matrix[i].begin(), matrix[i].end()) );            
    
    }
    
    vector<int> res;
    for(int i=0; i<matrix[0].size(); i++) {
        
        int mx = INT_MIN;
        for(int j=0; j<matrix.size(); j++) {
            if( mx < matrix[j][i] ) {
                mx = matrix[j][i];
            }
            
        }
        if( find(minV.begin(), minV.end(), mx) != minV.end()) {
                res.push_back(mx);
        }
    }
    
    return res;
}

void print_vector(vector<int>& v) {
    for(int a : v) {
        cout << a << " ";
    }
}

int main() {

    vector<vector<int>> v = { {1,10,4,2}, {9,3,8,7}, {15,16,17,12} };

    vector<int> res = luckyNumbers(v);

    print_vector(res);

/*
Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
Output: [12]
*/

    return 1;
}