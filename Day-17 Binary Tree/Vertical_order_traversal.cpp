/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});
    vector<vector<int>> temp;
    map<int, vector<int>> m;
    while(!q.empty())
    {
        auto it = q.front().first;
        int line = q.front().second;
        q.pop();
        m[line].push_back(it->data);
        if(it->left != NULL)
            q.push({it->left, line-1});
        if(it->right != NULL)
            q.push({it->right, line+1});
    }
    for(auto it : m)
    {
        temp.push_back(it.second);
    }
    for(int i = 0; i < temp.size(); i++)
    {
        for(int j = 0; j < temp[i].size(); j++)
        {
            ans.push_back(temp[i][j]);
        }
    }
    return ans;
}