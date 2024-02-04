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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head->next) return head;
        
        int prev = head->val;
        ListNode* temp = head->next;
        ListNode* ptr = head;
        while(temp) {
            int cur = temp->val;
            int gcd = __gcd(prev , cur);
            ptr->next = new ListNode(gcd);
            ptr->next->next = temp;
            ptr = temp;
            temp = temp->next;
            prev = cur;
            
        }
        
        return head;
    }
};