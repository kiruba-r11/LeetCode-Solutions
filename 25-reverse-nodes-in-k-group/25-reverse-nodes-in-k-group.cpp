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
    ListNode* solve(ListNode* head , int k) {
        
        if(!head) return head;
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        int K = k;
        
        while(k-- && temp) {
            prev = temp;
            temp = temp->next;
        }
        
        if(k == -1) {
            ListNode* newStart = prev->next;
            prev->next = NULL;
            
            ListNode* old = head;
            head = reverse(head);
            old->next = solve(newStart , K);
        }
        
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        return solve(head , k);
    }
};