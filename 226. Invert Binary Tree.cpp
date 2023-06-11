/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void find(TreeNode* root)
    {
        if(!root)
            return;
        
        swap(root->left,root->right);
        find(root->left);
        find(root->right);

    }
    TreeNode* invertTree(TreeNode* root) {
        
        if(!root)
            return root;
        
        find(root);

        return root;
    }
};
