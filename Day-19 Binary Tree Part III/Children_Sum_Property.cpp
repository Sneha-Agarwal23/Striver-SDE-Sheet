/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) 
{
    if(root == NULL)
        return;
    int csum = 0;
    if(root->left != NULL)
        csum = csum + root->left->data;
    if(root->right != NULL)
        csum = csum + root->right->data;
    if(csum > root->data)
    {
        root->data = csum;
    }
    else
    {
        if(root->left != NULL)
            root->left->data = root->data;
        if(root->right != NULL)
            root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int sum = 0;
    if(root->left != NULL)
        sum = sum + root->left->data;
    if(root->right != NULL)
        sum = sum + root->right->data;
    if(root->left != NULL || root->right != NULL)
    {
        root->data = sum;
    }
}  