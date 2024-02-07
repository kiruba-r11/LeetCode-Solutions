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
    int sumEvenGrandparent(TreeNode* root) {
        
        queue <vector <TreeNode*>> q;
        q.push({NULL , NULL , root});
        
        int sum = 0;
        
        while(!q.empty()) {
            int count = q.size();
            for(int it = 0; it < count; it++) {
                TreeNode* grandparent = q.front()[0];
                TreeNode* parent = q.front()[1];
                TreeNode* node = q.front()[2];
                q.pop();
                
                if(grandparent && grandparent->val % 2 == 0) {
                    sum += node->val;
                }
                
                if(node->left) q.push({parent , node , node->left});
                if(node->right) q.push({parent , node , node->right});
            }
        }
        
        return sum;
    }
};