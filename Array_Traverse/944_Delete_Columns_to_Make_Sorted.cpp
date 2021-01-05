//https://leetcode.com/problems/delete-columns-to-make-sorted/

#include <iostream>
#include <vector>

using namespace std;

int minDeletionSize(vector<string>& A) {
    int count = 0;
    
    if( A.empty() ) return -1;
    
    for( int i=0; i<A[0].size(); i++ ) {
        for( int j=0; j<A.size()-1; j++ ) {
            if( A[j][i] > A[j+1][i] ) {
                count++;
                break;
            }
        }
    }
    
    return count;
}

int main() {

    vector<string> A = {"zyx","wvu","tsr"};
    
    cout << minDeletionSize(A);

    return 1;
}