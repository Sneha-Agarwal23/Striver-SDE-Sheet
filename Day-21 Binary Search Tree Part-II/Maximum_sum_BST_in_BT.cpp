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
class Solution {
public:
    struct S{
        bool isBST;
        int sum;
        int maxval;
        int minval;
    };
    
    S dfs(TreeNode* root, int& ans)
    {
        if(root == NULL)
            return {true, 0, INT_MIN, INT_MAX};
        
        S l = dfs(root->left, ans);
        S r = dfs(root->right, ans);
        
        if(l.isBST && r.isBST && l.maxval < root->val && r.minval > root->val)
        {
            int sum = l.sum + r.sum + root->val;
            ans = max(ans, sum);
            return {true, sum, max(r.maxval, root->val), min(l.minval, root->val)};
        }
        else
        {
            return {false, 0, 0, 0};
        }
    }
    int maxSumBST(TreeNode* root) 
    {
        int ans = 0;
        dfs(root, ans);
        return ans;
        
    }
};