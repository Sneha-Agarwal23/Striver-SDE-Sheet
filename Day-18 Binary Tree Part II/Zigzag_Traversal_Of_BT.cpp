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
    vector<vector<int>> result;   
    void dfs(TreeNode* root, int depth)
    {
        if(root == NULL)
            return;
        if(result.size() == depth)
            result.push_back({});
        
        result[depth].push_back(root->val);
        dfs(root->left, depth+1);
        dfs(root->right, depth+1);
            
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        dfs(root, 0);
        for(int i = 1; i < result.size(); i = i+2)
        {
            reverse(result[i].begin(), result[i].end());
        }
        return result;
        
    }
};