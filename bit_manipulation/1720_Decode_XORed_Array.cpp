//https://leetcode.com/problems/decode-xored-array/

#include <iostream>
#include <vector>

using namespace std;

vector<int> decode(vector<int>& encoded, int first) {
    vector<int> result(encoded.size()+1);
    result[0] = first;
    
    for(int i=0;i<encoded.size();i++) {
        result[i+1]= encoded[i] ^ result[i];
    }
    
    return result;
}

int main() {

    vector<int> v = {1,2,3};

    decode(v, 1);

    return 1;
}