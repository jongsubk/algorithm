/* 1252_Cells_with_Odd_Values_in_a_Matrix */
// https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

#include <iostream>
#include <vector>
using namespace std;

int oddCells(int n, int m, vector<vector<int>>& indices) {
    vector<vector<int>> mat(n, vector<int>(m, 0));
    
    for(int i=0; i<indices.size(); i++) {
        int row = indices[i][0];
        int col = indices[i][1];
        
        for(int j=0; j<m; j++) { mat[row][j]++; }
        for(int k=0; k<n; k++) { mat[k][col]++; }
    }
    
    int res = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if( (mat[i][j] %2) == 1 ) {
                res++;
            }
        }
    }
    return res;
}


int main() {
    
    vector<vector<int>> v = { {0,1}, {1,1} };
    oddCells(2,3, v);

    return 1;
}