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
    int val = -1;
    void inorder(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) {
            if(val == -1) val = root->val;
            else {
                root->val += val;
                val = root->val;
            }
            return ;
        }
        
        inorder(root->right);
        root->val += val;
        val = root->val;
        inorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        return root;
    }
};