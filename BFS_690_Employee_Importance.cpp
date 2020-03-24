//https://leetcode.com/problems/employee-importance/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    
    /* FAIL - my initial code
    int getImportance(vector<Employee*> employees, int id) {
        int dp[2001][2] = { {-1,0}, };
        
        //make graph for BFS
        for(Employee* emp : employees) {
            dp[emp->id][1] = emp->importance;
            
            for(int sub : emp->subordinates) {
                dp[sub][0] = emp->id;
            }
        }
        
        queue<int> myq;
        myq.push(id);
        int sum = dp[id][0];
        
        while( !myq.empty() ) {
            int temp = myq.front(); myq.pop();
            
            for(int i=0; i<2001; i++) {
                if( temp == id ) {
                    sum += dp[i][0];
                    myq.push(i);
                }
            }
        }
        
        return sum;
    }*/
    
    //BFS
    /*
    int getImportance(vector<Employee*> employees, int id) {
    
        unordered_map<int, Employee*> m;
        for( Employee* employee : employees ) {
            m[employee->id] = employee;
        }
        
        queue<Employee*> q;
        q.push( m[id] );
        int sum=0;

        while( !q.empty() ) {
            
            Employee* e = q.front();  q.pop();
            sum += e->importance;
            
            for( int i : e->subordinates ) {
                q.push( m[i] );
            }
        }
        return sum;
    }
    */
    
    //DFS
    void DFS(unordered_map<int, Employee*>& m, int id, int& sum) {
        
        sum += m[id]->importance;
        
        for( int i : m[id]->subordinates ) {
            DFS(m, i, sum);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        
        unordered_map<int, Employee*> m;
        for( Employee* employee : employees ) {
            m[employee->id] = employee;
        }
        
        int sum=0;
        DFS(m, id, sum);
        return sum;
    }
};


int main() {

    /*
    Input: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
    Output: 11
    */
    //make input data structure
    vector<Employee*> v;
    vector<int> v1; v1.push_back(2); v1.push_back(3); 
    Employee* e = new Employee; e->id=1; e->importance=5; e->subordinates = v1;
    v.push_back(e);

    vector<int> v2;
    Employee* e2 = new Employee; e2->id=2; e2->importance=3; e2->subordinates = v2;
    v.push_back(e2);

    vector<int> v3;
    Employee* e3 = new Employee; e3->id=3; e3->importance=3; e3->subordinates = v3;
    v.push_back(e3);
    //

    Solution sol;
    cout << sol.getImportance(v,1);

    return 1;
}