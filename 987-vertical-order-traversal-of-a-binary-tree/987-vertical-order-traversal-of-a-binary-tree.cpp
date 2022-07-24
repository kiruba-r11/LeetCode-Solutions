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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue <pair <TreeNode* , int>> q;
        q.push({root , 1});
        
        map <int , map <int , priority_queue <int , vector <int> , greater <int>>>> hash;
        
        int mnl = 1e9 , mxl = -1e9;
        int lvl = 0;
        
        while(!q.empty()) {
            int count = q.size();
            for(int it = 0; it < count; it++) {
                TreeNode* node = q.front().first;
                int level = q.front().second;
                
                q.pop();
                
                hash[level][lvl].push(node->val);
                
                mnl = min(mnl , level);
                mxl = max(mxl , level);
                
                if(node->left) q.push({node->left , level - 1});
                if(node->right) q.push({node->right , level + 1});
            }
            lvl++;
        }
        
        vector <vector <int>> ans;
        
        for(int i = mnl; i <= mxl; i++) {
            vector <int> temp;
            for(auto j: hash[i]) {
                while(!hash[i][j.first].empty()) {
                    temp.push_back(hash[i][j.first].top());
                    hash[i][j.first].pop();
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};