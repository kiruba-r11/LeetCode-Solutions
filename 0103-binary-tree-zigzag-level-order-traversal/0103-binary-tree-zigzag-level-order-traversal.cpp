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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector <vector <int>> res;
        if(root == NULL) return res;
        
        queue <TreeNode*> q;
        q.push(root);
        
        int level = 0;
        while(!q.empty()) {
            vector <int> ans;
            int count = q.size();
            for(int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                ans.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level & 1) {
                reverse(ans.begin() , ans.end());
                res.push_back(ans);
            }
            else res.push_back(ans);
            level++;
        }
        
        return res;
    }
};