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
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newHead = reverse(head->next);
        
        head->next->next = head;
        head->next = NULL;
        
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast) {
            fast = fast->next;
            if(fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        ListNode* newHead = slow->next;
        slow->next = NULL;
        
        newHead = reverse(newHead);
        while(head && newHead) {
            if(head->val != newHead->val) return false;
            head = head->next;
            newHead = newHead->next;
        }
        
        return true;
    }
};