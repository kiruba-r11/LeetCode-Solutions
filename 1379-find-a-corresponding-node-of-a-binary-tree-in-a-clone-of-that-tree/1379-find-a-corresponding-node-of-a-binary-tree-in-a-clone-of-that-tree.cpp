/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* solve(TreeNode* p , TreeNode* q , TreeNode* t) {
        if(!p) return p;
        if(p == t) return q;
        
        TreeNode* left = solve(p->left , q->left , t);
        if(left) return left;
        
        TreeNode* right = solve(p->right , q->right , t);
        if(right) return right;
        
        return NULL;
    }
    
    TreeNode* getTargetCopy(TreeNode* p, TreeNode* q, TreeNode* t) {
        return solve(p , q , t);
    }
};