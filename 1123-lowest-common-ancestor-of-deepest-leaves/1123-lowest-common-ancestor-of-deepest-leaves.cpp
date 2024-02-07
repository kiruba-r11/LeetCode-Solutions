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
    pair <int , TreeNode*> depth(TreeNode* root) {
        if(!root) return {0 , NULL};
        if(!root->left && !root->right) return {1 , root};
        
        pair <int , TreeNode*> left = depth(root->left);
        pair <int , TreeNode*> right = depth(root->right);
        
        if(left.first == right.first) {
            return {1 + left.first , root};
        } 
        if(left.first > right.first) {
            return {1 + left.first , left.second};
        }
        
        return {1 + right.first , right.second};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return depth(root).second;
    }
};