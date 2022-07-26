/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void pre(BinaryTreeNode<int>* root, int key, int& pred)
{
    while(root != NULL)
    {
        if(root->data < key)
        {
            pred = root->data;
            root = root->right;
        }
        else if(root->data >= key)
        {
            root = root->left;
        }
    }
}
void suc(BinaryTreeNode<int>* root, int key, int& succ)
{
    while(root != NULL)
    {
        if(root->data > key)
        {
            succ = root->data;
            root = root->left;
        }
        else if(root->data <= key)
        {
            root = root->right;
        }
    }
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pred = -1;
    int succ = -1;
    pre(root, key, pred);
    suc(root, key, succ);
    return {pred, succ};
    
}
