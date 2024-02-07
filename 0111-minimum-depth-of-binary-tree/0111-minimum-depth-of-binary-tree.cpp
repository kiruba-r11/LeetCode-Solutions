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
    int ans = INT_MAX;
    void depth(TreeNode* root , int count) {
        
        if(!root) return;
        if(!root->left && !root->right) {
            ans = min(ans , count + 1);
            return;
        }
        
        depth(root->left , count + 1);
        depth(root->right , count + 1);
    }
    int minDepth(TreeNode* root) {
        depth(root , 0);
        return ans == INT_MAX ? 0 : ans;
    }
};