/************************************************************

    Following is the TreeNode class structure

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
void view(TreeNode<int> *root, int level, int& maxlevel, vector<int>& ans)
{
    if(root == NULL)
        return;
    if(level > maxlevel)
    {
        ans.push_back(root->data);
        maxlevel = level;
    }
    view(root->left, level+1, maxlevel, ans);
    view(root->right, level+1, maxlevel, ans);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    int maxlevel = 0;
    view(root, 1, maxlevel, ans);
    return ans;
}