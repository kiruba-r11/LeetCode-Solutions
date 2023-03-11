/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(ListNode* &input , int low , int high) {
        if(low > high) return NULL;
        int mid = low + (high - low) / 2;
        
        TreeNode* leftSub = solve(input , low , mid - 1);
        TreeNode* root = new TreeNode(input->val);
        input = input->next;
        root->left = leftSub;
        TreeNode* rightSub = solve(input , mid + 1 , high);
        root->right = rightSub;
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        int len = 0;
        
        ListNode* temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }
        return solve(head , 0 , len - 1);
    }
};





