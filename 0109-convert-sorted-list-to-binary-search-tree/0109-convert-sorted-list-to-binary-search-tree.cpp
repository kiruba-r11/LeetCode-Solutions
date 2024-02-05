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
    TreeNode* tree(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast) {
            fast = fast->next;
            if(fast) {
                prev = slow;
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        TreeNode* root = new TreeNode(slow->val);
        prev->next = NULL;
        fast = slow->next;
        slow->next = NULL;
        root->left = tree(head);
        root->right = tree(fast);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return tree(head);
    }
};