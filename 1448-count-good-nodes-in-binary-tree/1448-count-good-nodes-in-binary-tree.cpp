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
    void goodnode(TreeNode* root , int val) {
        if(!root) return;
        if(root->val >= val) ans++;
        goodnode(root->left , max(root->val , val));
        goodnode(root->right , max(root->val , val));
    }
    int goodNodes(TreeNode* root) {
        goodnode(root , root->val);
        return ans;
    }
};