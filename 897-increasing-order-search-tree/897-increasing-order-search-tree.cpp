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
    TreeNode* temp = NULL , *head = NULL;
    void solve(TreeNode* root) {
        TreeNode* node = new TreeNode(root->val);
        if(!temp) {
            head = temp = node;
        }
        else {
            temp->left = NULL;
            temp->right = node;
            temp = temp->right;
        }
    }
    
    void fun(TreeNode* root) {
        if(!root) return;
        fun(root->left);
        solve(root);
        fun(root->right);
        return ;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        fun(root);
        return head;
    }
};