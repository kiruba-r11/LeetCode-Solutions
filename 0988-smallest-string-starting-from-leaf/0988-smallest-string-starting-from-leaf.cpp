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
    string ans = "";
    string compare(string a , string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        for(; i >= 0 && j >= 0; i-- , j--) {
            if(a[i] < b[j]) return a;
            if(a[i] > b[j]) return b;
        }
        
        return a.size() < b.size() ? a : b;
    }
    void small(TreeNode* root , string &cur) {
        if(!root) return;
        if(!root->left && !root->right) {
            cur.push_back(char(root->val + 97));
            if(ans == "") ans = cur;
            else {
                ans = compare(ans , cur);
            }
            cur.pop_back();
            return;
        }
        cur.push_back(char(root->val + 97));
        small(root->left , cur);
        small(root->right , cur);
        cur.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        string cur = "";
        small(root , cur);
        reverse(ans.begin() , ans.end());
        return ans;
    }
};