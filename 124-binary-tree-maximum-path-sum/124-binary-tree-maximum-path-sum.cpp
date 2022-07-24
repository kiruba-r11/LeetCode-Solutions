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
    pair <int , int> solve(TreeNode* root) {
        if(!root) return {-1e9 , -1e9};
        if(!root->left && !root->right) return {root->val , root->val};
        
        pair <int , int> l = solve(root->left);
        pair <int , int> r = solve(root->right);
        
        return {
            max(root->val , root->val + max(l.first , r.first)) ,
            max(
                max(
                    max(l.second , r.second) ,
                    max(l.first , r.first)
                ),
                max(l.first + r.first + root->val , root->val)
            )   
        };
    }
    int maxPathSum(TreeNode* root) {
        pair <int , int> p = solve(root);
        return max(p.first , p.second);
    }
};