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
class CBTInserter {
private:
    queue <TreeNode*> q;
    TreeNode* rootNode = NULL;
public:
    CBTInserter(TreeNode* root) {
        q.push(root);
        rootNode = root;
        bool check = true;
        
        while(!q.empty() && check) {
            int count = q.size();
            
            for(int i = 0; i < count; i++) {
                TreeNode* node = q.front();
                
                if(node->left) q.push(node->left);
                else {
                    check = false;
                    break;
                }
                
                if(node->right) q.push(node->right);
                else {
                    check = false;
                    break;
                }
                
                q.pop();
            }
        }
    }
    
    int insert(int val) {
        TreeNode* newnode = new TreeNode(val);
        TreeNode* parent = q.front();

        
        if(parent->left) {
            parent->right = newnode;
            q.pop();
            q.push(newnode);
            return parent->val;
        }
        
        parent->left = newnode;
        q.push(newnode);
        return parent->val;
    }
    
    TreeNode* get_root() {
        return rootNode;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */