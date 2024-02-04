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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        if(!head->next->next) return {-1 , -1};
        
        int dist = 2;
        int prev = head->val;
        ListNode* cur = head->next;
        int start = -1 , start2 = -1 , near = 1e7 , far = -1 , cnt = 0;;
        
        while(cur && cur->next) {
            int next = cur->next->val;
            if((cur->val > prev && cur->val > next) || (cur->val < prev && cur->val < next)) {
                cnt++;
                if(start == -1) {
                    start = dist;
                    start2 = dist;
                } else {
                    near = min(near , dist - start);
                    start = dist;
                    far = dist - start2;
                }
            }
            
            dist++;
            prev = cur->val;
            cur = cur->next;
        }
        
        if(cnt <= 1) return {-1 , -1};
        return {near , far};
    }
};