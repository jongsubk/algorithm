//https://leetcode.com/problems/symmetric-tree/solution/
#include <iostream>
#include <queue>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

#if 0 //recurse
bool helper(TreeNode* t1, TreeNode* t2) {
    //stop condition
    if( t1 == NULL && t2 == NULL) return true;
    if( t1 == NULL || t2 == NULL) return false;
    
    if( t1->val != t2->val ) return false;
    
    return helper(t1->left, t2->right) && helper(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) {
    return helper(root, root);
}
#endif

#if 1 //iterative.. bfs
bool isSymmetric(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(root);
    
    while( !q.empty() ) {
        TreeNode* t1 = q.front(); q.pop();
        TreeNode* t2 = q.front(); q.pop();
        
        if( t1 == NULL && t2==NULL) continue;
        if( t1 == NULL || t2==NULL) return false;
        if( t1->val != t2->val) return false;

        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);        
    }

    return true;
}
#endif

int main() {

    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(1);
    TreeNode* t = new TreeNode(2,t1,t2);

    cout << isSymmetric(t);

    return 0;
}