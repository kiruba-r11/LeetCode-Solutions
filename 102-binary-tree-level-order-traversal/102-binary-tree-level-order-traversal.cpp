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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        /*
        
        O(N) time and space (queue) complexity
        Idea ->
            
            1. Queue Counter Method
            2. Null Insertion Method
            3. Parent - Child Queue Method
        
        */
        
        if(root == NULL) return {};
        
        // Method 1
        // --------------------------------------------------------------------------
//         queue <TreeNode*> q;
//         q.push(root);
        
//         vector <vector <int>> ans;
        
//         while(!q.empty()) {
//             int count = q.size();
//             vector <int> curLevel;
            
//             for(int it = 0; it < count; it++) {
//                 TreeNode* node = q.front();
//                 q.pop();
                
//                 curLevel.push_back(node->val);
                
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
            
//             ans.push_back(curLevel);
//         }
        
//         return ans;
            
        // --------------------------------------------------------------------------
        
        // Method 2
        // --------------------------------------------------------------------------
//         queue <TreeNode*> q;
//         q.push(root);
//         q.push(NULL);
        
//         vector <vector <int>> ans;
//         vector <int> curLevel;
        
//         while(!q.empty()) {
//             TreeNode* node = q.front();
//             q.pop();
            
//             if(node == NULL) {
//                 ans.push_back(curLevel);
//                 curLevel = {};
//                 if(!q.empty()) q.push(NULL);
//             } else {
//                 curLevel.push_back(node->val);
                
//                 if(node->left) q.push(node->left);
//                 if(node->right) q.push(node->right);
//             }
//         }
        
//         return ans;
        
        // --------------------------------------------------------------------------
        
        // Method 3
        // --------------------------------------------------------------------------
        queue <TreeNode*> pq , cq;
        pq.push(root);
        
        vector <vector <int>> ans;
        
        while(!pq.empty()) {
            cq = pq;
            pq = {};
            vector <int> curLevel;
            while(!cq.empty()) {
                TreeNode* node = cq.front();
                cq.pop();
                
                curLevel.push_back(node->val);
                
                if(node->left) pq.push(node->left);
                if(node->right) pq.push(node->right);
            }
            
            ans.push_back(curLevel);
        }
        
        return ans;
        
        // --------------------------------------------------------------------------
    }
};