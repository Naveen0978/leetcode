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
    vector<int> ans;
    void find(TreeNode* root,int lvl)
    {   
        if(!root)
            return;
        
        if(lvl == ans.size())
            ans.push_back(root->val);
        
        find(root->right,lvl+1);
        find(root->left,lvl+1);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return ans;
        
        find(root,0);

        return ans;
    }
};
