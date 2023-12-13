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
    void solve(TreeNode* root , vector <int> &cur , vector <vector <int>> &ans , int sum) {
    
        if(!root) return;
        
        if(!root->left && !root->right) {
            if(sum == root->val) {
                cur.push_back(root->val);
                ans.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        
        cur.push_back(root->val);
        solve(root->left , cur , ans , sum - root->val);
        solve(root->right , cur , ans , sum - root->val);
        cur.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <vector <int>> ans;
        vector <int> cur;
        solve(root , cur , ans , targetSum);
        return ans;
    }
};