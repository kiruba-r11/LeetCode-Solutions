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
    bool isCompleteTree(TreeNode* root) {
        queue <TreeNode*> q;
        q.push(root);
        
        int empty = 0;
        while(!q.empty()) {
            int count = q.size();
            for(int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left) {
                    if(empty == -1) return false;
                    q.push(node->left);
                }
                else empty = -1;
                if(node->right) {
                    if(empty == -1) return false;
                    q.push(node->right); 
                }
                else empty = -1;
            }
        }
        
        return true;
    }
};