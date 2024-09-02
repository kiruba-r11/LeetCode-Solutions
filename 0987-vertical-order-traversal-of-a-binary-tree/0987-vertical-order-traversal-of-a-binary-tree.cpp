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
    void solve(TreeNode* root , int width , int level , map <int , priority_queue <pair <int , int>>> &hash) {
        if(!root) return;
        
        hash[width].push({-1 * level , -1 * root->val});
        solve(root->left , width - 1 , level + 1 , hash);
        solve(root->right , width + 1 , level + 1 , hash);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map <int , priority_queue <pair <int , int>>> hash;
        solve(root , 0 , 0 , hash);
        
        vector <vector <int>> ans;
        
        for(auto i: hash) {
            vector <int> temp;
            priority_queue <pair <int , int>> pq = i.second;
            while(!pq.empty()) {
                temp.push_back(-1 * pq.top().second);
                pq.pop();
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};