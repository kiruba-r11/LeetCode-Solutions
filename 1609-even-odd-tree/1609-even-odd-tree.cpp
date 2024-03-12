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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        queue <TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int count = q.size();
            int elem = 0;
            if(level & 1) elem = 1e6 + 1;
            for(int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(level & 1) {
                    if(node->val & 1 || elem <= node->val) return false;
                    elem = node->val;
                } else {
                    if(!(node->val & 1) || elem >= node->val) return false;
                    elem = node->val;
                }
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
        
        return true;
    }
};