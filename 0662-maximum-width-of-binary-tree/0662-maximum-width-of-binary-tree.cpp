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
    int widthOfBinaryTree(TreeNode* root) {
        queue <pair <TreeNode* , long long>> q;
        q.push({root , 0});
        int ans = 0;
        
        while(!q.empty()) {
            int count = q.size();
            int minval = -1;
            int maxval = -1;
            for(int i = 0; i < count; i++) {
                TreeNode* node = q.front().first;
                long long val = q.front().second;
                
                if(i == 0) minval = val;
                val -= minval;
                
                if(i == count - 1) maxval = val;
                
                q.pop();
                
                if(node->left) q.push({node->left , 2 * val + 1});
                if(node->right) q.push({node->right , 2 * val + 2});
            }
            ans = max(ans , maxval + 1);
        }
        
        return ans;
    }
};