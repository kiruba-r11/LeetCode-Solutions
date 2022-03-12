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
    vector<int> postorderTraversal(TreeNode* root) {
       
         /*
        
        O(N) time and space complexity
        Idea -> Recursion or (stack + iteration)
        
        */
        
        vector <int> ans;
        if(root == NULL) return ans;
        
        stack <pair <TreeNode* , int>> s;
        s.push({root , 1});
        
        while(!s.empty()) {
         
            pair <TreeNode* , int> value = s.top();
            s.pop();
            
            TreeNode* node = value.first;
            int state = value.second;
            
            if(state == 1) {
                
                s.push({node , 2});
                if(node->left) s.push({node->left , 1});
                
            } else if(state == 2) {
                
                s.push({node , 3});
                if(node->right) s.push({node->right , 1});
                
            } else {
                
                ans.push_back(node->val);
            }
        }
        
        return ans;
    }
};