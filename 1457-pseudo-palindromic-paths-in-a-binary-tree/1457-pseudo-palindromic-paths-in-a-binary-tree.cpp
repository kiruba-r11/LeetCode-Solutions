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
    int palindrome(TreeNode* root , vector <int> &hash , int mask) {
        if(!root) return 0;
        if(!root->left && !root->right) {
            int odd = 0;
            // hash[root->val]++;
            mask = mask ^ (1 << root->val);
            // for(int i = 1; i < 10; i++) {
            //     if(hash[i] & 1) {
            //         odd++;
            //     }
            // }
            if((mask & (mask - 1)) == 0) return 1;
            // hash[root->val]--;
            mask = mask ^ (1 << root->val);
            // if(odd <= 1) return 1;
            return 0;
        }
        // hash[root->val]++;
        mask = mask ^ (1 << root->val);
        int left = palindrome(root->left , hash , mask);
        int right = palindrome(root->right , hash , mask);
        // hash[root->val]--;
        mask = mask ^ (1 << root->val);
        return left + right;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector <int> hash(10);
        return palindrome(root , hash , 0);
    }
};