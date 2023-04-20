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
        q.push({root , 1});
        
        long long ans = 0;
        
        while(!q.empty()) {
            int count = q.size();
            long long minw = 0;
            
            for(int it = 0; it < count; it++) {
                TreeNode* node = q.front().first;
                long long width = q.front().second;
                q.pop();
            
                if(it == 0) {
                    minw = width;
                    if(width != 1) minw--;
                    width = 1;
                } else {
                    width -= minw;
                }
                ans = max(ans , width);
                
                if(node->left) q.push({node->left , width * 2 + 1});
                if(node->right) q.push({node->right , width * 2 + 2});
            }
        }
        
        return int(ans);
    }
};