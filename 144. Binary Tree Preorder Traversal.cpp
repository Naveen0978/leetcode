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
    /*
    // iterative
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> preord;
        if(root == NULL)
            return preord;
        
        stack<TreeNode *> st;
        st.push(root);

        while(!st.empty())
        {
            TreeNode* topNode = st.top();
            preord.push_back(topNode->val);
            st.pop();
            if(topNode->right != NULL)
                st.push(topNode->right);
            if(topNode->left != NULL)
                st.push(topNode->left);
        }        
        return preord;
    }
    */
    
    //recursive
    void traversal(TreeNode* root, vector<int> &preord)
    {
        if(root == NULL)
            return;
        
        preord.push_back(root->val);
        traversal(root->left,preord);
        traversal(root->right,preord);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preord;

        traversal(root,preord);
        return preord;        
    }
};
