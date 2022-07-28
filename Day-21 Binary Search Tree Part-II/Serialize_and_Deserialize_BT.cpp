/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(root == NULL)
            return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
        
    }
    
    TreeNode* buildtree(queue<string>& q)
    {
        string s = q.front();
        q.pop();
        if(s == "null")
            return NULL;
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildtree(q);
        root->right = buildtree(q);
        return root;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        string s = "";
        queue<string> q;
        for(char c : data)
        {
            if(c == ',')
            {
                q.push(s);
                s = "";
                continue;
            }
            s = s + c;
        }
        return buildtree(q);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));