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
    int findmax(vector <int> &nums , int start , int end) {
    
        int maxval = start;
        for(int i = start; i <= end; i++) {
            if(nums[maxval] < nums[i]) {
                maxval = i;
            }
        }
        
        return maxval;
    }
    
    TreeNode* build(vector <int> &nums , int start , int end) {
        
        if(start > end) return NULL;
        
        int idx = findmax(nums , start , end);
        TreeNode* root = new TreeNode(nums[idx]);
        
        root->left = build(nums , start , idx - 1);
        root->right = build(nums , idx + 1 , end);
        
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums , 0 , nums.size() - 1);
    }
};