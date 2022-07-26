/*************************************************************
 
    Following is the Binary Tree node structure

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
void check(BinaryTreeNode<int> *root, bool& flag)
{
    if(root == NULL)
        return;
    
    if(root->left != NULL)
    {
        if(root->left->data > root->data)
        {
            flag = false;
            return;
        }
            
    }
    if(root->right != NULL)
    {
        if(root->right->data < root->data)
        {
            flag = false;
            return;
        }       
    }
    check(root->left, flag);
    check(root->right, flag);
    
}
bool validateBST(BinaryTreeNode<int> *root) 
{
    bool flag = true;
    if(root == NULL)
        return true;
    check(root, flag);
    return flag;
    
}