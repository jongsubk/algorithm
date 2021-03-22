//https://leetcode.com/problems/univalued-binary-tree/
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


bool helper(TreeNode* node, int val) {
    
    if( node->val == val ) 
        return true;
    
    return false;
}
bool isUnivalTree(TreeNode* root) {
    if( root == nullptr ) {
        return true;
    }
    
    if(root->left) { 
        if( ! helper(root->left, root->val) ) {
            return false;
        }
        
        if( isUnivalTree(root->left) == false ) 
            return false;
    }
    
    if(root->right) { 
        if( ! helper(root->right, root->val) ) {
            return false;
        }
        
        if( isUnivalTree( root->right) == false ) 
            return false;
    }

    return true;
}

int main() {

    return 1;
}

/*
Input: [2,2,2,5,2]
Output: false
*/