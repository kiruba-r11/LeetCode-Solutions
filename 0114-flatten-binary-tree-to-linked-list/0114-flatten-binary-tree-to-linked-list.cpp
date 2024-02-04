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
    void flat(TreeNode* root) {
        
        if(!root) return ;
        
        flat(root->left);
        flat(root->right);
        TreeNode* left = root->left;
        TreeNode* leftptr = root->left;
        
        while(leftptr && leftptr->right) {
            leftptr = leftptr->right;
        }
        if(leftptr) {
            leftptr->right = root->right;
            root->right = root->left;
        }
        
        root->left = NULL;
        
        // return root;
    }
    void flatten(TreeNode* root) {
        flat(root);
        
    }
};