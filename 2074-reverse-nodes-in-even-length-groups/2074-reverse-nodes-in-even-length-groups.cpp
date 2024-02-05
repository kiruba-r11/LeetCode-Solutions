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
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        ListNode* temp = head;  
        ListNode* prev = NULL;
        for(int k = 1; temp; k++) {
            ListNode* before = prev;
            int cnt = 0;
            for(int i = 1; i <= k && temp; i++) {
                prev = temp;
                temp = temp->next;
                cnt++;
            }
            if(cnt % 2 == 0) {
                prev->next = NULL;
                ListNode* newHead = reverse(before->next);
                if(before->next) before->next->next = temp;
                prev = before->next;
                before->next = newHead;
            }
        }
        
        return head;
    }
};

    
