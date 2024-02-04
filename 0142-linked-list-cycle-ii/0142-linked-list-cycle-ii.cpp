/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast) {
            fast = fast->next;
            if(fast) {
                slow = slow->next;
                fast = fast->next;
            }
            
            if(slow == fast) break;
        }
        
        if(fast == NULL) return NULL;
        
        slow = head;
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
        
    }
};
