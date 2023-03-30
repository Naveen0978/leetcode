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

    void traversal(TreeNode* root, vector<int>& inord)
    {
        if(root == NULL)
            return;

        traversal(root->left,inord);
        inord.push_back(root->val);
        traversal(root->right,inord);
    }
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;                
        traversal(root,ans);

        return ans;
    }
};
