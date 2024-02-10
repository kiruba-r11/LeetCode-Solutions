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
    pair <int , int> path(TreeNode* root) {
        if(!root) return {-1 , -1};
        pair <int , int> left = path(root->left);
        pair <int , int> right = path(root->right);

        ans = max(ans , max(left.first , right.second));
        
        return {left.second + 1 , right.first + 1};
    }
    int longestZigZag(TreeNode* root) {
        pair <int , int> res = path(root);
        return max(ans , max(res.first , res.second));
    }
};