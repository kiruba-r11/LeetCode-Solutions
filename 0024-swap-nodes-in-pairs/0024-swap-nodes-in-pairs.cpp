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
    ListNode* swap(ListNode* head) {
    
        if(!head || !head->next) return head;
        
        ListNode* cur = head;
        ListNode* next = head->next;
        
        ListNode* newhead = swap(next->next);
        
        cur->next = newhead;
        next->next = cur;
        
        return next;
        
    }
    
    ListNode* swapPairs(ListNode* head) {
        return swap(head);
    }
};