//https://leetcode.com/problems/maximum-binary-tree/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* helper(vector<int> v, int left, int right) {

    //stop condition
    if( left > right) return NULL;

    //find mex value, index
    int idx=left;
    for(int i=left; i<=right; i++) {
        if( v[i] > v[idx] ) idx=i;
    }

    TreeNode* root = new TreeNode( v[idx] );
    root->left = helper(v, left, idx-1);
    root->right = helper(v, idx+1, right);

    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& v) {
    return helper( v, 0, v.size()-1);
}

int main() {
    vector<int> v = {3,2,1,6,0,5};

    TreeNode* root = constructMaximumBinaryTree(v);

    return 0;
}