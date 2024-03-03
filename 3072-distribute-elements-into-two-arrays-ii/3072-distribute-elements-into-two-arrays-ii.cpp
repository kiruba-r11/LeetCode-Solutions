#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>  

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        ordered_set s1 , s2;
        
        int n = nums.size(); 
        vector <int> a , b;
        
        a.push_back(nums[0]);
        b.push_back(nums[1]);
        
        s1.insert(nums[0]);
        s2.insert(nums[1]);
        
        int i = 2; 
        while(i < n) {
            int n1 = a.size() - s1.order_of_key(nums[i] + 1);
            int n2 = b.size() - s2.order_of_key(nums[i] + 1);
            
            if(n1 > n2) {
                a.push_back(nums[i]);
                s1.insert(nums[i]);
            } else if(n1 < n2) {
                b.push_back(nums[i]);
                s2.insert(nums[i]);
            } else {
                if((int)a.size() <= (int)b.size()) {
                    a.push_back(nums[i]);
                    s1.insert(nums[i]);
                } else {
                    b.push_back(nums[i]);
                    s2.insert(nums[i]);
                } 
            }
            i++;
        }
        
        vector <int> ans;
        for(int i = 0; i < a.size(); i++) ans.push_back(a[i]);
        for(int i = 0; i < b.size(); i++) ans.push_back(b[i]);
        
        return ans;
    }
};