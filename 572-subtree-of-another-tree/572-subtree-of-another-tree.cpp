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
    bool search(TreeNode* p , TreeNode* q) {
        
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;
        
        bool left = search(p->left , q->left);
        if(!left) return false;
        
        bool right = search(p->right , q->right);
        if(!right) return false;
        
        return true;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
            
        bool find = search(root , subRoot);
        if(find) return true;
        
        bool left = isSubtree(root->left , subRoot);
        if(left) return true;
        
        bool right = isSubtree(root->right , subRoot);
        if(right) return true;
        
        return false;
    }
};