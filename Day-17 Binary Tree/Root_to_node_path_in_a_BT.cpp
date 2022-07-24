/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void path(TreeNode* A, int B, vector<int>& ans, vector<int> v)
{
    if(A == NULL)
    {
        return;
    }
    v.push_back(A->val);
    if(B == A->val)
    {
        for(int i = 0; i < v.size(); i++)
        {
            ans.push_back(v[i]);
        }
        return;
    }
    path(A->left, B, ans, v);
    path(A->right, B, ans, v);
    
}
vector<int> Solution::solve(TreeNode* A, int B) 
{
    vector<int> ans;
    vector<int> v;
    path(A, B, ans, v);
    return ans;
    
}
