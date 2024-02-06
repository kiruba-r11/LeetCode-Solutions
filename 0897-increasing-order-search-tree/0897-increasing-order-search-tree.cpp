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
    TreeNode* flatten(TreeNode* root) {
        if(!root) return root;
        
        TreeNode* left = flatten(root->left);
        TreeNode* right = flatten(root->right);
        
        root->right = right;
        if(!left) return root;
        
        TreeNode* newRoot = left;
        while(left && left->right) {
            left = left->right;
        }
        
        left->right = root;
        root->left = NULL;
        return newRoot;
    }
    TreeNode* increasingBST(TreeNode* root) {
        return flatten(root);
    }
};