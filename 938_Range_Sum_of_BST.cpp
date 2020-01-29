/* 938. Range Sum of BST */
// https://leetcode.com/problems/range-sum-of-bst/

#include <iostream>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// method 1
int rangeSumBST(TreeNode* root, int L, int R) {
    int sum=0;
    if( ! root ) return 0;
    
    if( root->val >= L && root->val <= R) {
        sum += root->val;
    }
    
    sum += rangeSumBST(root->left, L, R);
    sum += rangeSumBST(root->right, L, R);
    
    return sum;
}

//method 2
/*
int rangeSumBST(TreeNode* root, int L, int R) {
    int sum=0;
    helper(root, L, R, sum);
    
    return sum;
}

void helper(TreeNode* node, int L, int R, int& sum) {
    if( !node ) return;
    
    if( node->val >= L && node->val <= R) {
        sum += node->val;
    }
    helper(node->left, L, R, sum);
    helper(node->right, L, R, sum);
}
*/

int main() {

    

    return 1;
}