#include <iostream>
#include <stack>
#include <queue>

using namespace std;

/*class TreeNode {
public:
    TreeNode *left;
    TreeNode *right;
};

// 104. Maximum Depth of Binary Tree 
//Using BFS
int maxDepth(TreeNode *root)
{
    if(root == NULL)
        return 0;
    
    int res = 0;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        ++ res;
        for(int i = 0, n = q.size(); i < n; ++ i)
        {
            TreeNode *p = q.front();
            q.pop();
            
            if(p->left != NULL)
                q.push(p -> left);
            if(p->right != NULL)
                q.push(p -> right);
        }
    }
    
    return res;
}
*/

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> v;
    //recurse solution
    //recurseTraverse(root, v);
    
    //iterative solution
    stack<TreeNode*> s;
    s.push(root);
    while( !s.empty() ) {
        
        TreeNode* node = s.top();
        s.pop();

        if( node->left != nullptr ) {
            s.push(node->left);
        } else {
            v.push_back(node->val);
        }
            
        if( root -> right != nullptr ) {
            s.push(node->right);
        } else {
            v.push_back(node->val);
        }
    }
    
    return v;
}


int main() {

    stack<int> st;
    st.push(1); st.push(2); st.push(3);
    cout << st.top();
    st.pop();
    cout << st.top();
    
    TreeNode* root = new TreeNode(9);
    inorderTraversal(root);

}