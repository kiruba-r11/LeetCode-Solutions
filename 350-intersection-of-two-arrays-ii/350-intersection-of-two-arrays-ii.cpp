class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        /*
        
        O(NlogN) time and O(N) (output array) space complexity
        Idea -> Sorting
        
        */
        
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        
        int i = 0 , j = 0;
        int n1 = nums1.size() , n2 = nums2.size();
        
        vector <int> ans;
        
        while(i < n1 && j < n2) {
            
            if(nums1[i] < nums2[j]) i++;
            else if(nums1[i] > nums2[j]) j++;
            else {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            
        }
        
        return ans;
    }
};