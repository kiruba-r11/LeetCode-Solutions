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
    bool find(TreeNode* root , int k) {
        if(!root) return false;
        if(root->val == k) return true;
        
        if(root->val > k) return find(root->left , k);
        return find(root->right , k);
    }
    bool findT(TreeNode* root, int k , TreeNode* t) {
        if(!root) return false;
        
        int newval = k - root->val;
        bool check = false;
        
        if(newval < root->val) check = find(t , newval);
        if(newval > root->val) check = find(t , newval);
        if(check) return true;
        
        bool left = findT(root->left , k , t);
        if(left) return true;
        
        bool right = findT(root->right , k , t);
        if(right) return true;
        
        return false;
    }
    
    bool findTarget(TreeNode* root , int k) {
        return findT(root , k , root);
    }
};