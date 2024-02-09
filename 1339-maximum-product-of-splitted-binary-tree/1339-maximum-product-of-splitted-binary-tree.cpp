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
    long long ans = 0;
    int mod = 1e9 + 7;
    int sumtree(TreeNode* root , int sum) {
        if(!root) return 0;
        int left = sumtree(root->left , sum);
        int right = sumtree(root->right , sum);
        
        int total = root->val + left + right;
        
        ans = max(ans , total * 1LL * abs(total - sum));
        // ans = ans % mod;
        // cout << ans << endl;
        
        return total;
    }
    int maxProduct(TreeNode* root) {
        int sum = sumtree(root , 0);
        ans = 0;
        // cout << sum << endl;
        sumtree(root , sum);
        ans = ans % mod;
        return (int)ans;
    }
};