/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void bview(TreeNode<int>* root, vector<int>& ans)
{
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    bview(root->left, ans);
    bview(root->right, ans);
}

void rview(TreeNode<int>* root, vector<int>& ans)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return;
    if(root->right != NULL)
        rview(root->right, ans);
    else
        rview(root->left, ans);
    ans.push_back(root->data);
}
void lview(TreeNode<int>* root, vector<int>& ans)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return;
    ans.push_back(root->data);
    if(root->left != NULL)
        lview(root->left,ans);
    else
        lview(root->right,ans);
}
vector<int> traverseBoundary(TreeNode<int>* root)
{
    vector<int> ans;
    if(root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);
    lview(root->left, ans);
    bview(root->left, ans);
    bview(root->right, ans);
    rview(root->right, ans);
    return ans;
    
}