/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
class BSTiterator
{
    public:
    queue<int> q;
    void inorder(TreeNode<int> *root)
    {
        if(root == NULL)
            return;
        
        inorder(root->left);
        q.push(root->data);
        inorder(root->right);
    }
    BSTiterator(TreeNode<int> *root)
    {
        inorder(root);
    }

    int next()
    {
        int a = q.front();
        q.pop();
        return a;
    }

    bool hasNext()
    {
        return !q.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/