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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(n == 1) {
            if(!head->next) return NULL;
            
            ListNode* prev = NULL;
            ListNode* temp = head;
            while(head && head->next) {
                prev = head;
                head = head->next;
            }
            prev->next = NULL;
            return temp;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        
        while(n-- && fast) {
            fast = fast->next;
        }
        
        while(fast) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        
        if(prev == NULL) {
            head = head->next;
        } else {
            prev->next = slow->next;
        }
        
        return head;
    }
};