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
        
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = head->next;
        
        while(next) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        
        cur->next = prev;
        head = cur;
        
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode* newHead = new ListNode(-1);
        ListNode* headptr = newHead;
        
        int sum = 0 , carry = 0;
        
        while(l1 && l2) {
            sum = l1->val + l2->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            
            newHead->next = l1;
            newHead = newHead->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1) {
            sum = l1->val + carry;
            l1->val = sum % 10;
            carry = sum / 10;
            
            newHead->next = l1;
            newHead = newHead->next;
            l1 = l1->next;
        }
        
        while(l2) {
            sum = l2->val + carry;
            l2->val = sum % 10;
            carry = sum / 10;
            
            newHead->next = l2;
            newHead = newHead->next;
            l2 = l2->next;
        }
        
        if(carry) {
            ListNode* newnode = new ListNode(carry);
            newHead->next = newnode;
        }
        
        return reverse(headptr->next);
    }
};