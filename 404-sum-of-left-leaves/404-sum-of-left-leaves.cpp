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
    int solve(TreeNode* root , bool isLeft) {
    
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) {
            if(isLeft) return root->val;
            return 0;
        }
        
        int left = solve(root->left , true);
        int right = solve(root->right , false);
        
        return left + right;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        /*
        
        O(N) time and space (stack) complexity
        Idea -> DFS
        
        */
        
        return solve(root , false);
        
    }
};