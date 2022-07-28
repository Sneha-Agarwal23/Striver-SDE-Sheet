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
void inorder(TreeNode<int> *root, vector<int>& v)
{
    if(root == NULL)
        return;
    
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	vector<int> v;
    inorder(root, v);
    return v[k-1];
}