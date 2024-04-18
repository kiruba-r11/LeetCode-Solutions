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
    int ans = 0;
    void solve(TreeNode* root , int target , long long sum , map <long long , int> &hash) {
        if(!root) return;
        
        sum += root->val;
        ans += hash[sum - target];
        hash[sum]++;
        
        solve(root->left , target , sum , hash);
        solve(root->right , target , sum , hash);
        
        hash[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        map <long long , int> hash;
        hash[0] = 1;
        solve(root , targetSum , 0 , hash);
        return ans;
    }
};

