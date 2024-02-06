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
    int sumTree(TreeNode* root , int low , int high) {
        if(!root) return 0;
        
        int sum = 0;
        int left = 0;
        int right = 0;
        
        if(root->val < low) return sumTree(root->right , low , high);
        if(root->val > high) return sumTree(root->left , low , high);
        
        if(root->val >= low && root->val <= high) sum += root->val;
        right = sumTree(root->right , low , high);
        left = sumTree(root->left , low , high);
        
        return sum + left + right;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return sumTree(root , low , high);
    }
};