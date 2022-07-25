/************************************************************

    Following is the TreeNode class structure.

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
void preorder(TreeNode<int> *root, vector<int>& a)
{
    if(root == NULL)
        return;
    
    a.push_back(root->data);
    preorder(root->left, a);
    preorder(root->right, a);
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    vector<int> a;
    preorder(root, a);
    TreeNode<int> * head = root;
    for(int i = 1; i < a.size(); i++)
    {
        root->right = new TreeNode<int>(a[i]);
        root = root->right;
    }
    return head;
        
}