//https://leetcode.com/problems/subdomain-visit-count/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> m;
    
    for(string s : cpdomains) {
        int i = s.find(" ");
        int count = stoi( s.substr( 0, i ));
        string domain = s.substr(i+1);
        m[domain] += count;
                            
        for(int i=0 ;i< s.size(); i++) {
            if( s[i] == '.' ) {
                m[ s.substr(i+1) ] += count;
            }
        }
    }
    
    vector<string> result;
    for(auto a : m) {
        result.push_back( to_string(a.second) + " " + a.first ); 
    }
    
    return result;
}


int main() {
    vector<string> v = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};

    vector<string> v_r = subdomainVisits(v);

    for(string s : v_r) {
        cout << s << " ,";
    }

    return 1;
}