#include <iostream>
#include <vector>
#include <map>
using namespace std;


    vector<int> partitionLabels(string S) {
        vector<int> ans;
        if(S.length()==0) {
            return ans;
        }
        map<char,int> mp;
        for(int i=0;i<S.length();i++) {
            mp[S[i]]=i;
        }
        int start=0,end=0;
        for(int i=0;i<S.length();i++) {
            end= max(end,mp[S[i]]);
            if(end==i) {
                ans.push_back(end-start+1);
                start=end+1;
            }
        }
        return ans;
    }

    int main()
    {
        string s ="abcdefghjqwer";

        vector<int> v = partitionLabels(s);

        return 1;

    }