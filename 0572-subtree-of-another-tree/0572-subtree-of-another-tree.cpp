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
    bool subtree(TreeNode* root , TreeNode *sub) {
        if(!root && !sub) return true;
        if(!root || !sub) return false;
        
        if(root->val != sub->val) return false;
        
        bool left = subtree(root->left , sub->left);
        if(!left) return false;
        
        bool right = subtree(root->right , sub->right);
        if(!right) return false;
        
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* sub) {
        if(!root && !sub) return true;
        if(!root || !sub) return false;
        
        if(subtree(root , sub)) return true;
        bool left = isSubtree(root->left , sub);
        if(left) return true;
        
        bool right = isSubtree(root->right , sub);
        if(right) return true;
        
        return false;
    }
};