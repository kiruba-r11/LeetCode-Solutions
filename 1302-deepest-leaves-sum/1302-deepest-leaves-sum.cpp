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
    int depth(TreeNode* root) {
        if(!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        
        return max(left , right) + 1;
    }
    int sum(TreeNode* root , int depth) {
        if(!root) return 0;
        if(!root->left && !root->right) {
            if(depth == 0) return root->val;
            return 0;
        }
        
        int leftSum = sum(root->left , depth - 1);
        int rightSum = sum(root->right , depth - 1);
        
        return leftSum + rightSum;
    }
    int deepestLeavesSum(TreeNode* root) {
        int treeDepth = depth(root) - 1;
        int treeSum = sum(root , treeDepth);
        
        return treeSum;
    }
};