#include <iostream>
#include <vector>
using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    vector<int> result;
    
    int i;
    for(i=0; i<prices.size()-1; i++) {
        int min_index = i;
        
        for(int j= i+1; j<prices.size(); j++) {
            if( prices[min_index] >= prices[j] ) {
                min_index = j;
                break;
            }
        }
        
        if( i == min_index ) {
            result.push_back( prices[i] );
        }
        else {
            result.push_back( prices[i]- prices[min_index] );
        }
    }
    result.push_back( prices[i] );
    
    return result;
}

int main() {

    vector<int> v = {8,4,6,2,3};
    vector<int> res = finalPrices(v);

    for( int a : res ) {
        cout << a << " ";
    }

    return 1;
}
