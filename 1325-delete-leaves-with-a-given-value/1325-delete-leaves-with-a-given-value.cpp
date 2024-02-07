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
    TreeNode* leafs(TreeNode* root , int target) {
        if(!root) return root;
        if(!root->left && !root->right) {
            if(target == root->val) return NULL;
            return root;
        }
        
        root->left = leafs(root->left , target);
        root->right = leafs(root->right , target);
        
        if(!root->left && !root->right) {
            if(root->val == target) return NULL;
            return root;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return leafs(root , target);
    }
};