/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string serializeHelper(TreeNode* root) {
        if(!root) return "n";
        
        string val = to_string(root->val);
        string left = serializeHelper(root->left);
        string right = serializeHelper(root->right);
        
        string ans = "";
        ans += val;
        ans += "," + left + "," + right;
        return ans;
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = serializeHelper(root);
        return ans;
    }

    TreeNode* deserializeHelper(string &data , int &idx) {
        if(idx == data.size()) return NULL;
        
        string temp = "";
        int i = idx , n = data.size();
        while(i < n && data[i] != ',') {
            temp += data[i];
            i++;
        }
        
        idx = i + 1;
        
        TreeNode* root = new TreeNode(-1);

        if(temp != "n") {
            if(temp != "") {
                int val = stoi(temp);
                root->val = val;
            }
        } else {
            return NULL;
        }
        
        root->left = deserializeHelper(data , idx);
        root->right = deserializeHelper(data , idx);
        
        return root;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return deserializeHelper(data , idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));