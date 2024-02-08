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
    int palindrome(TreeNode* root , vector <int> &hash) {
        if(!root) return 0;
        if(!root->left && !root->right) {
            int odd = 0;
            hash[root->val]++;
            for(int i = 1; i < 10; i++) {
                if(hash[i] & 1) {
                    odd++;
                }
            }
            hash[root->val]--;
            if(odd <= 1) return 1;
            return 0;
        }
        hash[root->val]++;
        int left = palindrome(root->left , hash);
        int right = palindrome(root->right , hash);
        hash[root->val]--;
        return left + right;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector <int> hash(10);
        return palindrome(root , hash);
    }
};