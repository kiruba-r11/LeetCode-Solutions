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
    bool flip(TreeNode* r1 , TreeNode* r2) {
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        
        if(r1->val != r2->val) return false;
        bool ll = flip(r1->left , r2->left);
        bool lr = flip(r1->left , r2->right);
        bool rl = flip(r1->right , r2->left);
        bool rr = flip(r1->right , r2->right);
        
        return (ll || lr) && (rl || rr);
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return flip(root1 , root2);
    }
};