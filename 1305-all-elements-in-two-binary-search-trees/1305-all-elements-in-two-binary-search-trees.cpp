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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector <int> ans;
        
        stack <pair <TreeNode* , int>> s1 , s2;
        
        if(root1 != NULL)
            s1.push({root1 , 1});
        
        if(root2 != NULL)
            s2.push({root2 , 1});
        
        while(!s1.empty() && !s2.empty()) {
            
            int stackOne = INT_MAX , stackTwo = INT_MAX;
            TreeNode *node1 = NULL , *node2 = NULL;
            
            if(!s1.empty()) {
                pair <TreeNode* , int> node = s1.top();
                s1.pop();
                
                // Denotes preorder
                if(node.second == 1) {
                    // Insert the current node for inorder
                    s1.push({node.first , 2});
                    
                    // Insert the left child if it is present
                    if(node.first->left != NULL) s1.push({node.first->left , 1});  
                }
                // Denotes inorder
                else if(node.second == 2) {
                    // Insert the current node for postorder
                    s1.push({node.first , 3});
                    
                    stackOne = min(stackOne , node.first->val);
                    node1 = node.first;
                }
            }
            
            if(!s2.empty()) {
                pair <TreeNode* , int> node = s2.top();
                s2.pop();
                
                // Denotes preorder
                if(node.second == 1) {
                    // Insert the current node for inorder
                    s2.push({node.first , 2});
                    
                    // Insert the left child if it is present
                    if(node.first->left != NULL) s2.push({node.first->left , 1});  
                }
                // Denotes inorder
                else if(node.second == 2) {
                    // Insert the current node for postorder
                    s2.push({node.first , 3});
                    
                    stackTwo = min(stackTwo , node.first->val);
                    node2 = node.first;
                }
            }
            
            if(stackOne != INT_MAX && stackTwo != INT_MAX) {
                if(stackOne == stackTwo) {
                    ans.push_back(stackOne);
                    ans.push_back(stackTwo);
                    
                    if(node1->right != NULL) s1.push({node1->right , 1});
                    if(node2->right != NULL) s2.push({node2->right , 1});
                } else if(stackOne < stackTwo) {
                    ans.push_back(stackOne);
                    
                    pair <TreeNode* , int> node = s2.top();
                    s2.pop();
                    
                    s2.push({node.first , 2});
                    
                    if(node1->right != NULL) s1.push({node1->right , 1});
                } else {
                    ans.push_back(stackTwo);
                    
                    pair <TreeNode* , int> node = s1.top();
                    s1.pop();
                    
                    s1.push({node.first , 2});
                    
                    if(node2->right != NULL) s2.push({node2->right , 1});
                }
            } else if(stackOne != INT_MAX) {
                
                pair <TreeNode* , int> node = s1.top();
                s1.pop();

                s1.push({node.first , 2});
                
            } else if(stackTwo != INT_MAX) {
                
                pair <TreeNode* , int> node = s2.top();
                s2.pop();

                s2.push({node.first , 2});
                
            }
        }
        
        while(!s1.empty()) {
            pair <TreeNode* , int> node = s1.top();
            s1.pop();

            // Denotes preorder
            if(node.second == 1) {
                // Insert the current node for inorder
                s1.push({node.first , 2});

                // Insert the left child if it is present
                if(node.first->left != NULL) s1.push({node.first->left , 1});  
            }
            // Denotes inorder
            else if(node.second == 2) {
                // Insert the current node for postorder
                s1.push({node.first , 3});
                
                ans.push_back(node.first->val);

                // Insert the right child it if is present
                if(node.first->right != NULL) s1.push({node.first->right , 1});
            }
        }
        
        while(!s2.empty()) {
            pair <TreeNode* , int> node = s2.top();
            s2.pop();

            // Denotes preorder
            if(node.second == 1) {
                // Insert the current node for inorder
                s2.push({node.first , 2});

                // Insert the left child if it is present
                if(node.first->left != NULL) s2.push({node.first->left , 1});  
            }
            // Denotes inorder
            else if(node.second == 2) {
                // Insert the current node for postorder
                s2.push({node.first , 3});
                
                ans.push_back(node.first->val);

                // Insert the right child it if is present
                if(node.first->right != NULL) s2.push({node.first->right , 1});
            }
        }
     
        return ans;
    }
};