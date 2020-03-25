//https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void helper( vector<vector<int>>& ans, TreeNode* node, int level ) {
        //stop condition
        if( !node ) { return; }
        
        if( level == ans.size() ) { ans.push_back({}); }
        
        ans[level].push_back(node->val);
        
        helper(ans, node->left, level+1);
        helper(ans, node->right, level+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        
        helper(ans, root, 0);
        
        reverse( ans.begin(), ans.end() );  //<algorithm>
        return ans;
    }

};


int main() {

    return 1;
}