/* 1277_Count_Square_Submatrices_with_All_Ones */
//https://leetcode.com/problems/count-square-submatrices-with-all-ones/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countSquares(vector<vector<int>>& M) {
    int res=0;
    for(int i=0;i<M.size();++i) //all rows
        for(int j=0;j<M[i].size();++j){ // all columns
            if(i && j && M[i][j]) { // exclude first row/col and zeros
                M[i][j] = min(M[i-1][j-1], min(M[i-1][j],M[i][j-1])) +1; // find max size of square at this corner by looking one step backwards
            }
            res += M[i][j]; // add number of squares (max size) at this corner
        }
    return res;
}

/* //my sol.
int subMatrix(int m, int n, vector<vector<int>>& matrix) {
    if( m >= matrix.size() || n >= matrix[0].size() ) { return 0; }
    
    int sum=0;
    if( matrix[m][n] == 1) {
        sum++;
    }
    sum += subMatrix(m+1, n, matrix);
    sum += subMatrix(m, n+1, matrix);
    
    return sum;
}
int countSquares(vector<vector<int>>& matrix) {
    return subMatrix(1,2,matrix);
}
*/

int main()
{
    vector<vector<int>> matrix = {{0,1,1,1,}, {1,1,1,1}, {0,1,1,1}};
    cout << countSquares(matrix);
}    
