//589. N-ary Tree Preorder Traversal
//https://leetcode.com/problems/n-ary-tree-preorder-traversal/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:

    //Iterative solution using stack
    vector<int> preorder(Node* root) {
        if( root == nullptr )
            return {};
        
        vector<int> result;
        stack<Node*> st;
        st.push(root);
        
        while( !st.empty() ) {
            Node* n = st.top();
            result.push_back( n->val );
            st.pop();
            
            for(int i= n->children.size()-1; i>=0; i--) {
                st.push(n->children[i]);
            }
        }        
        return result;
    }
    
    
    // Recursive solution
    /*
    void helper(Node* node, vector<int>& v) {
        if( node == nullptr ) return;
        
        v.push_back( node->val );
        
        for(Node* n: node->children) {
            helper(n,v);
        }
    }
    
    vector<int> preorder(Node* root) {
        vector<int> result;
        
        helper(root, result);
        
        return result;
    }
    */
};


int main() {
    
    /* example data
                 3
           5     5     5
          7 7   7 7   7 7
    */
    Node* root = new Node(3);
    vector<Node*> v1(3, new Node(5));
    root->children = v1;
    vector<Node*> v2(2, new Node(7));
    root->children[0]->children = v2;
    

    Solution s;
    vector<int> result = s.preorder(root);

    for(int a: result) {
        cout << a << ",";
    }

    return 1;
}