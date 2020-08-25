#include <iostream>
using namespace std;

class Solution {
public:
    
    string sortString(string s) {
        string result;
        
        int cnt[26]={};
        for(char c : s) {
            cnt[c-'a']++;
        }

        while( s.size() > result.size() ) {
            for(int i=0;i<26;i++){
                if( cnt[i] > 0 ) {
                    cnt[i]--;
                    result += 'a'+ i;
                }
            }
            for(int i=25;i>=0;i--){
                if( cnt[i] > 0 ) {
                    cnt[i]--;
                    result += 'a'+ i;
                }
            }
            
        }
        
        return result;
    }
};


int main() {

    Solution s;
    cout << s.sortString("abcfghdj");

    return 1;
}
