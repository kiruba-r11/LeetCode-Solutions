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
        
        if(head == NULL || head->next == NULL) return head;
        
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
    
    int getDecimalValue(ListNode* head) {
        
        /*
        
        O(N) time and O(1) space complexity
        Idea -> Reversal of List
        
        */
        
        head = reverse(head);
        int ans = 0 , pow = 1;
        
        while(head) {
            if(head->val) ans += pow;
            pow *= 2;
            head = head->next;
        }
        
        return ans;
    }
};