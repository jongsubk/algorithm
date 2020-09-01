//https://leetcode.com/problems/destination-city/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string destCity(vector<vector<string>>& paths) {
    unordered_map<string, string> map;
    for( vector<string> v : paths ) {
        map[v[0]] = v[1];
    }
    
    string start = paths[0][0];
    string old;
    while( start != "") {
        old = start;
        start = map[start];
    }
    
    return old;
}


int main() {

    vector<vector<string>> paths = {{ "London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};

    cout << destCity(paths);

    return 1;
}