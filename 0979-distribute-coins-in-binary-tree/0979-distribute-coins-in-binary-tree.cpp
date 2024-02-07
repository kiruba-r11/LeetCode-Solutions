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
    int ans = 0;
    int coins(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) {
            ans += abs(root->val - 1);
            return root->val - 1;
        }
        
        int left = coins(root->left);
        int right = coins(root->right);
        
        int total = root->val + left + right - 1;
        ans += abs(total);
        return total;
    }
    int distributeCoins(TreeNode* root) {
        coins(root);
        return ans;
    }
};