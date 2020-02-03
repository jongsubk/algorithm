/* 1038_Binary_Search_Tree_to_Greater_Sum_Tree */
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

#include <iostream>
using namespace std;


 //Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

void helper(TreeNode* node, int& val) {
    if( !node ) return;
    
    helper(node->right, val);
    
    node->val += val;
    val = node->val;
    
    helper(node->left, val);
}

TreeNode* bstToGst(TreeNode* root) {
    int val = 0;
    helper(root, val);
    
    return root; 
}

int main() {

    return 1;
}