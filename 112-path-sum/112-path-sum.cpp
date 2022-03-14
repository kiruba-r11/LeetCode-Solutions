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
    bool solve(TreeNode* root , int targetSum , int currentSum) {
    
        if(root == NULL) return false;
        
        if(root->left == NULL && root->right == NULL) {
            return targetSum == (currentSum + root->val);
        }
        
        bool left = solve(root->left , targetSum , currentSum + root->val);
        bool right = solve(root->right , targetSum , currentSum + root->val);
        
        return left || right;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        /*
        
        O(N) time and space (recursive stack) complexity
        
        */
        
        return solve(root , targetSum , 0);
    }
};