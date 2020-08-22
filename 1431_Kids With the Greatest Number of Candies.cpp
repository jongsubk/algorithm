//https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    //get maxinum candy in candies
    int max_candy = 0;
    for(int candy : candies) {
        if( max_candy < candy) {
            max_candy = candy;
        }
    }
    
    vector<bool> result(candies.size(), {false} );
    for( int i=0; i<candies.size(); i++ ) {
        if( candies[i] + extraCandies >= max_candy ) {
            result[i] = true;
        }
    }        
    return result;
}

int main() {
    vector<int> candies{2,3,5,1,3};
    vector<bool> result(candies.size());

    result = kidsWithCandies(candies, 3);

    for( bool res: result) {
        cout << res << ", ";
    }
    return 1;
}