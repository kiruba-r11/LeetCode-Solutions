/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* original , TreeNode* cloned , TreeNode* target) {
    
        
        if(original == NULL) return NULL;
        if(original == target) return cloned;
        
        TreeNode* left = solve(original->left , cloned->left , target);
        if(left != NULL) return left;
        TreeNode* right = solve(original->right , cloned->right , target);
        return right;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return solve(original , cloned , target);
    }
};