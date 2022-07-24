/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> bottomView(BinaryTreeNode<int> * root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
    
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    map<int, int> m;
    while(!q.empty())
    {
        auto it = q.front().first;
        int line = q.front().second;
        q.pop();
        m[line] = it->data;
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
