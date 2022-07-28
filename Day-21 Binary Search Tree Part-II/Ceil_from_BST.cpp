/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x)
{
    int ceilval = -1;
    while(node != NULL)
    {
        if(node->data == x)
        {
            ceilval = node->data;
            return ceilval;
        }
        else if(node->data > x)
        {
            ceilval = node->data;
            node = node->left;
        }
        else
            node = node->right;
    }
    return ceilval;
    
}