/* 1323. Maximum 69 Number */
// https://leetcode.com/problems/maximum-69-number/

#include <iostream>
#include <string>

using namespace std;

int maximum69Number (int num) {
    int res = num;
    string s = to_string(num);
    for(int i=0; i<s.size() ; i++) {
        
        if( s[i] == '6') {
            s[i] = '9';
            
            return stoi(s);
        }
    }
    return res;
}


int main() {

    cout << maximum69Number( 9669);

    return 1;
}