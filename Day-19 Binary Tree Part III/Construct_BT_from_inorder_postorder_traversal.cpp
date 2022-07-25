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
    TreeNode* BT(vector<int>& inorder, vector<int>& postorder, int start, int end, int& rootindex)
    {
        if(start > end)
            return NULL;
        
        int pivot = start;
        while(inorder[pivot] != postorder[rootindex])
        {
            pivot++;
        }
        rootindex--;
        TreeNode* tree = new TreeNode(inorder[pivot]);
        tree->right = BT(inorder, postorder, pivot+1, end, rootindex);
        tree->left = BT(inorder, postorder, start, pivot-1, rootindex);
        return tree;
        
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int rootindex = postorder.size()-1;
        return BT(inorder, postorder, 0, postorder.size()-1, rootindex);
        
    }
};