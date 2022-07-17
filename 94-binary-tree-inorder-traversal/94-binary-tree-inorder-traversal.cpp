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
    
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        
        vector <int> ans;
        stack <pair <TreeNode* , int>> s;
        
        s.push({root , 1});
        
        while(!s.empty()) {
            TreeNode* node = s.top().first;
            int val = s.top().second;
            s.pop();
            
            if(val == 1) {
                s.push({node , val + 1});
                if(node->left) s.push({node->left , 1});
            } else if(val == 2) {
                s.push({node , val + 1});
                ans.push_back(node->val);
                if(node->right) s.push({node->right , 1});
            } else {
                continue;
            }
        }
        
        return ans;
    }
};