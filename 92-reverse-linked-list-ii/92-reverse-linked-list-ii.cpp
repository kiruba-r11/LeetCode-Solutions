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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* h = new ListNode(-1);
        ListNode* temp = h;
        
        int index = 1;
        // left--;
        while(index < left && temp) {
            if(index == 1) {
                temp->next = head;
                temp = head;
            } else {
                temp = temp->next;
            }
            index++;
        }
        
        ListNode* next = NULL;
        ListNode* start = temp->next ? temp->next : head;
        ListNode* stemp = start;
        
        // right--;
        while(stemp && index < right) {
            index++;
            stemp = stemp->next;
        }
        
        if(stemp) {
            next = stemp->next;
            stemp->next = NULL;
        }
        
        start = reverse(start);
        temp->next = start;
        while(start && start->next) {
            start = start->next;
        }
        
        if(start)
        start->next = next;
        
        return h->next;
    }
};