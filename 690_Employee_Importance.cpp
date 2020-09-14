//https://leetcode.com/problems/employee-importance/

#include <iostream>
#include <vector>

using namespace std;

int helper(unordered_map<int, Employee*>& m, int id) {    
    int sum = m[id]->importance;
    
    for( int a : m[id]->subordinates ) {
        sum += helper(m, a);
    }
    
    return sum;
}
    
int getImportance(vector<Employee*> employees, int id) {
    
    unordered_map<int, Employee*> m;
    
    for( Employee* e : employees ) {
        m[e->id] = e;
    }
    
    return helper(m, id);
}

int main() {

    

    return 1;
}