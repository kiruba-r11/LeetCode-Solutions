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
    bool unival(TreeNode* root , int val) {
        if(!root) return true;
        if(root->val != val) return false;
        
        bool left = unival(root->left , val);
        bool right = unival(root->right , val);
        
        return left && right;
    }
    bool isUnivalTree(TreeNode* root) {
        return unival(root , root->val);
    }
};