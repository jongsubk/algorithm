//https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
/* 
Given a n-ary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
*/
/*
Input: root = [1,null,3,2,4,null,5,6]
Output: 3
*/
#include <iostream>
#include <vector>
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
    
    /*
    int max_depth=0;
    int maxDepth(Node* root, int depth=1) {
        
        if( root == NULL ) { return 0; }
        if( root->children.empty() ) { return 1; }
        
        vector<Node*> v = root->children;
        depth += 1;
        if( max_depth< depth) { max_depth=depth; }
        
        for( Node* node : v ) {
            
            maxDepth(node, depth);
        }
        return max_depth;  
    }
    */
    
    int maxDepth(Node* root) {
        if( !root ) return 0;
        
        int max_depth=1;
        for(Node* node : root->children ) {
            max_depth = max(max_depth, maxDepth(node)+1);
        }
        
        return max_depth;
    }
};


int main() {
    //make input data //Need debug 2020.0324
    vector<Node*> v;
    vector<Node*> v2;

    Node* root = new Node(1, v);
    v.push_back(new Node(3, v2));  v.push_back(new Node(2));  v.push_back(new Node(4)); 
    v2.push_back(new Node(5)); v2.push_back(new Node(6)); 
    //

    Solution sol;
    cout << sol.maxDepth(root);

    return 1;
}