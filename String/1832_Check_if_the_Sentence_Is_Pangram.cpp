//1832. Check if the Sentence Is Pangram
//https://leetcode.com/problems/check-if-the-sentence-is-pangram/

#include <iostream>

using namespace std;

bool checkIfPangram(string sentence) {
    bool check[26] = {0,};
    int count=0;
    
    for(char c : sentence) {
        int i = c-'a';
        if(check[i]==0) {
            check[i]=1;
            count++;
        }
        
        if( count==26) {
            return true;
        }
    }
    
    return false;
}


int main() {

    cout << checkIfPangram("abcdefghijklmnopqrstuvwxyz");

    return 1;
}