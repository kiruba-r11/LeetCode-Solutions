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
    unordered_map <int , int> freq;
    int hfreq = 0;
    vector <int> ans;
    int find(TreeNode* root) {
        if(!root) return 0;

        int left = find(root->left);
        int right = find(root->right);
        
        int cursum = root->val + left + right;
        freq[cursum]++;
        if(freq[cursum] > hfreq) {
            ans.clear();
            ans.push_back(cursum);
            hfreq = freq[cursum];
        } else if(freq[cursum] == hfreq) {
            ans.push_back(cursum);
        }
        
        return cursum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        find(root);
        return ans;
    }
};