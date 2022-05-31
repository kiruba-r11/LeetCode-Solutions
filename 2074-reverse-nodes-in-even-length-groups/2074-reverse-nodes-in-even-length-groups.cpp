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
    ListNode* reverse(ListNode* start , ListNode* prev , ListNode* end) {
        
        ListNode* p = NULL;
        ListNode* q = start;
        ListNode* r = start->next;
        
        while(r != end) {
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }

        q->next = p;
        start = q;
        
        return start;
    }
    
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* itr = dummy;
        int cnt = 1;
        while(temp) {
            int cur = 1;
            ListNode* start = temp;
            ListNode* end = temp;
            ListNode* prev = temp;
            int num = 0;
            while(cur <= cnt && temp) {
                prev = temp;
                temp = temp->next;
                cur++;
                num++;
            }
            end = temp;
            if(num % 2 == 0) {
                itr->next = reverse(start , prev , end);
                itr = start;
            } else {
                itr->next = start;
                itr = prev;
            }
            cnt++;
        }
        
        return dummy->next;
    }
};