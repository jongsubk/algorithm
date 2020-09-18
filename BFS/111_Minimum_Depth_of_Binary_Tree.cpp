//https://leetcode.com/problems/minimum-depth-of-binary-tree/

#include <iostream>
#include <queue>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* dfs
int helper(TreeNode* root, int depth) {
    if(root == NULL ) return 0;
    if( root->left==NULL && root->right==NULL)  return depth;
    
    if( root->left && root->right )
        return min( helper(root->left, depth+1), helper(root->right, depth+1) );
    
    return max( helper(root->left, depth+1), helper(root->right, depth+1) );
}

int minDepth(TreeNode* root) {
    return helper(root, 1);
}
*/

//bfs
int minDepth(TreeNode* root) {
    if( root == NULL) return 0;
    
    queue<TreeNode*> Q;
    Q.push(root);
    
    int depth=0;
    
    while( !Q.empty() ) {
        depth++;
        int k = Q.size();
        for(int i=0; i<k; i++) {
            TreeNode* t = Q.front();  Q.pop();
            
            if( t->left == NULL && t->right==NULL )
                return depth;
            
            if(t->left)    Q.push(t->left);
            if(t->right)   Q.push(t->right);
        }            
    }
    
    return 0;
}


int main() {

    cout << minDepth(NULL);
    return 0;
}