/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void inorder(BinaryTreeNode<int>* root, vector<int>& in)
    {
        if(root == NULL)
            return;
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
void preorder(BinaryTreeNode<int>* root, vector<int>& pr)
    {
        if(root == NULL)
            return;
        pr.push_back(root->data);
        preorder(root->left, pr);
        preorder(root->right, pr);
    }
void postorder(BinaryTreeNode<int>* root, vector<int>& po)
    {
        if(root == NULL)
            return;
        postorder(root->left, po);
        postorder(root->right, po);
        po.push_back(root->data);
    }
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> result;
    vector<int> in;
    vector<int> pr;
    vector<int> po;
    inorder(root, in);
    preorder(root, pr);
    postorder(root, po);
    result.push_back(in);
    result.push_back(pr);
    result.push_back(po);
    return result;
    
    
}