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
    void initialiseStack(stack <pair <TreeNode* , int>> &s , TreeNode* root) {
        
        if(root) s.push({root , 1});
    }
    
    void performTraversal(stack <pair <TreeNode* , int>> &s , bool canDoPostOrder , TreeNode* &currentNode , vector <int> &ans) {
        if(!s.empty()) {
            
            pair <TreeNode* , int> node = s.top();
            s.pop();

            // Denotes preorder
            if(node.second == 1) {
                // Insert the current node for inorder
                s.push({node.first , 2});

                // Insert the left child if it is present
                if(node.first->left != NULL) s.push({node.first->left , 1});  
            }
            // Denotes inorder
            else if(node.second == 2) {
                // Insert the current node for postorder
                s.push({node.first , 3});

                if(canDoPostOrder) {
                    ans.push_back(node.first->val);

                    // Insert the right child it if is present
                    if(node.first->right != NULL) s.push({node.first->right , 1});
                } else {
                    currentNode = node.first;
                }
            }
        }
    }
    
    void pushInorder(stack <pair <TreeNode* , int>> &s) {
        pair <TreeNode* , int> node = s.top();
        s.pop();

        s.push({node.first , 2});
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        /*
        
        Iterative Stack Solution with O(n) time and O(n) (stack + resultant array) space complexity
        Idea - Inorder gives elements in sorted order for a BST. So traverse and compare the inorder of both BST.
        
        */
        
        vector <int> ans;
        
        stack <pair <TreeNode* , int>> s1 , s2;
        
        // Intialise the stack
        initialiseStack(s1 , root1);
        initialiseStack(s2 , root2);
        
        while(!s1.empty() && !s2.empty()) {
            
            TreeNode *node1 = NULL , *node2 = NULL;
            
            if(!s1.empty()) {
                performTraversal(s1 , false , node1 , ans);
            }
            
            if(!s2.empty()) {
                performTraversal(s2 , false , node2 , ans);
            }
            
            // Both nodes are at inorder
            if(node1 && node2) {
                
                // Compare values
                if(node1->val == node2->val) {
                    ans.push_back(node1->val);
                    ans.push_back(node2->val);
                    
                    if(node1->right != NULL) s1.push({node1->right , 1});
                    if(node2->right != NULL) s2.push({node2->right , 1});
                } else if(node1->val < node2->val) {
                    ans.push_back(node1->val);
                    
                    pushInorder(s2);
                    
                    if(node1->right != NULL) s1.push({node1->right , 1});
                } else {
                    ans.push_back(node2->val);
                    
                    pushInorder(s1);
                    
                    if(node2->right != NULL) s2.push({node2->right , 1});
                }
            } 
            // Only first tree reached inorder, the second one is still in preorder
            else if(node1) {
                pushInorder(s1);
            } 
            // Only second tree reached inorder, the first one is still in preorder
            else if(node2) {
                pushInorder(s2);
            }
        }
        
        TreeNode* node = NULL;
        
        while(!s1.empty()) {
            performTraversal(s1 , true , node , ans);
        }
        
        while(!s2.empty()) {
            performTraversal(s2 , true , node , ans);
        }
     
        return ans;
    }
};