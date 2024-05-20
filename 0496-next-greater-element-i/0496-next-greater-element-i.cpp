class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        stack <int> s;
        map <int , int> hash;
        vector <int> ngr(n2 , -1);
        vector <int> ans(n1);
        
        for(int i = n2 - 1; i >= 0; i--) {
            hash[nums2[i]] = i;
            while(!s.empty() && s.top() < nums2[i]) s.pop();
            if(!s.empty()) ngr[i] = s.top();
            s.push(nums2[i]);
        }
        
        for(int i = 0; i < n1; i++) {
            ans[i] = ngr[hash[nums1[i]]];
        }
        
        return ans;
    }
};