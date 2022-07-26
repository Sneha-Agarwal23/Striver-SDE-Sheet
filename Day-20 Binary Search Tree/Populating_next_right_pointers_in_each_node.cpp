#Coding Ninja
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root)
{
    queue<BinaryTreeNode< int > *> q;
    if(root == NULL)
        return;
    
    q.push(root);
    while(!q.empty())
    {
        int s = q.size();
        for(int i = 1; i <= s; i++)
        {
            auto temp = q.front();
            q.pop();
            if(i < s)
                temp->next = q.front();
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
        }
    }
    
}

#Leetcode

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(root == NULL)
            return NULL;
        
        if(root->left != NULL)
            root->left->next = root->right;
        
        if(root->right != NULL && root->next != NULL)
            root->right->next = root->next->left;
        
        connect(root->left);
        connect(root->right);
        return root;
        
    }
};