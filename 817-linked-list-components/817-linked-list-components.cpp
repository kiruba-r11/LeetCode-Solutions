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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map <int , bool> hash;
        for(auto i: nums) hash[i] = true;
        
        ListNode* temp = head;
        int ans = 0;
        bool check = false;
        while(temp) {
            ListNode* t = temp;
            while(t && hash[t->val]) {
                check = true;
                t = t->next;
            }
            temp = t ? t->next : NULL;
            if(check)
                ans++;
            check = false;
        }
        return ans;
    }
};