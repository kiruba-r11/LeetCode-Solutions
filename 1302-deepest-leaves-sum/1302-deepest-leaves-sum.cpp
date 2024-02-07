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
    int depth = 0 , sum = 0;
    void deep(TreeNode* root , int d) {
        if(!root) return;
        if(!root->left && !root->right) {
            if(d > depth) {
                sum = root->val;
                depth = d;
            } else if(d == depth) {
                sum += root->val;
            }
            
            return;
        }
        
        deep(root->left , d + 1);
        deep(root->right , d + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        deep(root , 0);
        return sum;
    }
};