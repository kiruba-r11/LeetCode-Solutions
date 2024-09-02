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
    int find_height(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        return max(find_height(root->left) , find_height(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(!root->left && !root->right) return true;
        
        int leftHeight = find_height(root->left);
        int rightHeight = find_height(root->right);
        
        if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) return true;
        return false;
    }
};