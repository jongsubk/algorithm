#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
//using namespace std;

#if 0 //hash_map
int find_firstRepeating(vector<int>& v) {
  stdext::hash_map<int,int> m;
  for(int value : v) {
  
    if( m.find(value) == m.end() ){
      m[value] = 1;
    }
    else {
      return value;
    }
  }
  return -1;
}
#endif

#if 1 //unordered_map
int find_firstRepeating(const vector<int>& v) {

  unordered_map<int,int> m;
  for(int value : v) {
  
    if( m.find(value) == m.end() ){
      m[value] = 1;
    }
    else {
      return value;
    }
  }
  return -1;
}
#endif

/*
int find_firstRepeating(vector<int>& v) {
  
  vector<int> temp_v; 
  for(int i=0; i< (int)v.size(); i++) {
    for(int j : temp_v) {
      if( j == v[i]) { return j; }
    }
    temp_v.push_back( v[i] );
  }
  return -1;  
}
*/

// To execute C++, please define "int main()"
int main() {
  vector<int> v = { 3,5,6,6,8 };
  cout << find_firstRepeating(v);
  
  return 0;
}


/*

int main() {
    cout << "TEST";

    vector<int> v = { 1,3,-1,-3,5,3,6,7 };
    vector<int> result = maxSlidingWindow(v, 3);

    vector<int> v1 = {3,2,1,6,0,5};
    sort(v1.begin(), v1.end(), greater<int>());

    return 0;
}
*/