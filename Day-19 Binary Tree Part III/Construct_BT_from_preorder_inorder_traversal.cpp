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
    TreeNode* BT(vector<int>& preorder, vector<int>& inorder, int start, int end, int& rootindex)
    {
        if(start > end)
            return NULL;
        
        int pivot = start;
        while(inorder[pivot] != preorder[rootindex])
        {
            pivot++;
        }
        rootindex++;
        TreeNode* tree = new TreeNode(inorder[pivot]);
        tree->left = BT(preorder, inorder, start, pivot-1, rootindex);
        tree->right = BT(preorder, inorder, pivot+1, end, rootindex);
        return tree;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int rootindex = 0;
        return BT(preorder, inorder, 0, preorder.size()-1, rootindex);
        
    }
};