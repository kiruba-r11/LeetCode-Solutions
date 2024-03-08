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
    // Morris Traversal, Threaded Binary Tree
    // O(3*n) time, O(1) space
    
    TreeNode* get_right_most_node(TreeNode* left_node , TreeNode* cur_node) {
        while(left_node->right && left_node->right != cur_node) left_node = left_node->right;
        return left_node;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> inorder;
        
        TreeNode* cur_node = root;
        
        while(cur_node) {
            if(cur_node->left) {
                TreeNode* left_node = cur_node->left;
                TreeNode* right_most_node = get_right_most_node(left_node , cur_node);
                
                if(right_most_node->right) {
                    inorder.push_back(cur_node->val);
                    left_node->right = NULL;
                    
                    cur_node = cur_node->right;
                } else {
                    right_most_node->right = cur_node;
                    cur_node = cur_node->left;
                }
                
            } else {
                inorder.push_back(cur_node->val);
                cur_node = cur_node->right;
            } 
        }
        
        return inorder;
    }
};