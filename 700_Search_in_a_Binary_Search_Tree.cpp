//https://leetcode.com/problems/search-in-a-binary-search-tree/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //return condition
        if( root == nullptr )
            return nullptr;
        
        if( root->val == val ) {
            return root;
        }
        
        return root->val > val ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};


int main() {

    Solution sol;
    TreeNode* root = nullptr;

    sol.searchBST(root, 2);

    return 0;
}