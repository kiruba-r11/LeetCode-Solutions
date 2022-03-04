class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        /*
        
        O(N) time and space comeplexity
        Idea -> Stack (Next Greater Element to Right) + Hashing
        
        */
        
        int n1 = nums1.size() , n2 = nums2.size();
        vector <int> ngr(n1 , -1);
        stack <int> s;
        unordered_map <int , int> hash;
        
        s.push(nums2[n2 - 1]);
        
        for(int i = 0; i < n1; i++) {
            hash[nums1[i]] = i;
        }
        
        for(int i = n2 - 2; i >= 0; i--) {
            while(!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }
            if(!s.empty() && hash.find(nums2[i]) != hash.end()) ngr[hash[nums2[i]]] = s.top();
            s.push(nums2[i]);
        }
        
        return ngr;
    }
};