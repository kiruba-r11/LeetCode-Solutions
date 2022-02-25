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
    bool isCompleteTree(TreeNode* root) {
        
        
        /*
        
        O(N) time and space complexity
        Idea -> BFS
        
        Edge Cases -> 
            1. There cannot exist a right node for next level without having a left node.
               
               Example - 
               
                            |
                    |               |
                -       |       |       |
                
               Here (-) indicates a NULL
               
               
            2. If there is a left node, and no right node in the next level, then the next nodes in 
               the current level should not have both left and right nodes.
               
               Example - 
               
                            |
                    |               |
                |       -       |       |
                
               Here (-) indicates a NULL
            
            3. If there is no left and right node in the next level, then the next nodes in the current 
               level should have both left and right nodes. 
            
               Example - 
               
                            |
                    |               |
                -       -       |       |
                
               Here (-) indicates a NULL
               
            4. Except last level, all the levels should be perfectly filled
        
        */
        
        
        queue <TreeNode*> q;
        q.push(root);
        
        int cnt = 1;
        
        while(!q.empty()) {
            int count = q.size();
            bool miss = false;
            for(int it = 0; it < count; it++) {
                
                TreeNode* node = q.front();
                q.pop();
                
                if(node == NULL) {
                    if(q.empty() || q.front() == NULL) continue;
                    return false;
                }
                
                if(node->left) {
                    if(miss) return false;
                    q.push(node->left);
                }
                else {
                    if(node->right) return false;
                }
                if(node->right) {
                    if(miss) return false;
                    q.push(node->right);
                }
                else {
                    if(node->left) q.push(NULL);
                    else miss = true;
                }   
            }
            if(!q.empty()) {
                if(cnt != count) return false;
            }
            cnt *= 2;
        }
        
        return true;
    }
};