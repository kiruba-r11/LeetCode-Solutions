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
        
        ListNode* p = NULL;
        ListNode* q = head;
        ListNode* r = head->next;
        
        while(r) {
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        
        q->next = p;
        head = q;
        
        return head;
    }
    
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast) {
            fast = fast->next;
            if(fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        slow->next = reverse(slow->next);
        slow = slow->next;
        
        while(slow) {
            if(head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        
        return true;
    }
};