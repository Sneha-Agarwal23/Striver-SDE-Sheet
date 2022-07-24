/************************************************************

    Following is the TreeNode class structure:

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
vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    map<int, int> m;
    while(!q.empty())
    {
        auto it = q.front().first;
        int line = q.front().second;
        q.pop();
        if(m.count(line) == 0)
            m[line] = it->val;
        if(it->left != NULL)
        {
            q.push({it->left, line-1});
        }
        if(it->right != NULL)
        {
            q.push({it->right, line+1});
        }
    }
    for(auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
    
}