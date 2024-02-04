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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode* newHead = new ListNode(-1);
        ListNode* temp = newHead;
        
        ListNode* prev = head;
        ListNode* cur = head->next;
        
        while(cur) {
            bool check = true;
            while(cur && prev->val == cur->val) {
                cur = cur->next;
                check = false;
            }
            
            if(check) {
                temp->next = prev;
                temp = temp->next;
            }
            prev = cur;
            if(cur) cur = cur->next;
        }
        
        if(prev) {
            temp->next = prev;
            temp = temp->next;
        }
        
        temp->next = NULL;
        return newHead->next;
    }
};