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
    vector <int> in;
    void inorder(TreeNode* root) {
        if(!root) return ;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    
    vector <int> bs(int num) {
        int low = 0;
        int high = in.size() - 1;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(in[mid] == num) return {num , num};
            if(in[mid] < num) low = mid + 1;
            else high = mid - 1;
        }
        if(high == -1 && low == in.size()) return {-1 , -1};
        if(high == -1) return {-1 , in[low]};
        if(low == in.size()) return {in[high] , -1};
        return {in[high] , in[low]};
    }
    
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector <vector <int>> ans(queries.size());
        inorder(root);
        for(int i = 0; i < queries.size(); i++) {
            ans[i] = bs(queries[i]);
        }
        return ans;
    }
};