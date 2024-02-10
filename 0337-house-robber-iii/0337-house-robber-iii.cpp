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
    pair <int , int> house(TreeNode* root) {
        if(!root) return {0 , 0};
        if(!root->left && !root->right) return {root->val , 0};
        
        // include , don't include
        pair <int , int> left = house(root->left);
        pair <int , int> right = house(root->right);
        
        // include -> use don't include answers
        int include = left.second + right.second + root->val;
        
        // exclude -> use include answers
        int exclude = left.first + right.first;
        
        return {max(include , exclude) , exclude};
    }
    int rob(TreeNode* root) {
        pair <int , int> ans = house(root);
        return max(ans.first , ans.second);
    }
};