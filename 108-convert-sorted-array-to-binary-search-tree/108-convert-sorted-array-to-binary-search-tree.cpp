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
    TreeNode* insert(TreeNode* root , vector <int> nums , int low , int high) {
        
        if(low > high) return NULL;
        int mid = (low + high) / 2;
        
        root = new TreeNode(nums[mid]);
        root->left = insert(root->left , nums , low , mid - 1);
        root->right = insert(root->right , nums , mid + 1 , high);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = insert(root , nums , 0 , nums.size() - 1);
        return root;
    }
};