/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
void solve(TreeNode<int> *root, map<int, int>& m, int level)
{
    if(root == NULL)
        return;
    
    m[level]++;
    solve(root->left, m, level+1);
    solve(root->right, m, level+1);
}
int getMaxWidth(TreeNode<int> *root)
{
    int ans = 0;
    map<int, int> m;
    solve(root, m, 1);
    for(auto it : m)
    {
        int a = it.second;
        ans = max(ans, a);
    }
    return ans;
}