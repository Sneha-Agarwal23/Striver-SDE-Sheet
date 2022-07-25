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
    int result;
    int dfs(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        result = max(result, l+r+root->val);
        return max(0, max(l, r) + root->val);
    }
    int maxPathSum(TreeNode* root) 
    {
        if(root == NULL)
            return 0;
        result = root->val;
        dfs(root);
        return result;

        
    }
};