/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* tree(vector<int> &preOrder, int start , int end)
{
    if(start > end)
        return NULL;
    
    int mid = (start + end)/2;
    TreeNode<int>* temp = new TreeNode<int>(preOrder[mid]);
    temp->left = tree(preOrder, start , mid-1);
    temp->right = tree(preOrder, mid+1, end);
    return temp;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder)
{
    sort(preOrder.begin(), preOrder.end());
    if(preOrder.size() == 0)
        return NULL;
    return tree(preOrder, 0, preOrder.size() -1);
    
}