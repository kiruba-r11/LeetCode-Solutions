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
    int solve(TreeNode* root , int &d) {
        if(!root) return -1;
        if(!root->left && !root->right) return 0;
        
        int lh = solve(root->left , d);
        int rh = solve(root->right , d);
        
        d = max(d , max(max(lh + 1 , rh + 1) , lh + rh + 2));
        
        return max(lh , rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d = 0;
        solve(root , d);
        return d;
    }
};