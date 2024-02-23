class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        
        int n = nums.size();
        int evensum = 0 , oddsum = 0;
        int preeven = 0 , preodd = 0;
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(i & 1) oddsum += nums[i];
            else evensum += nums[i];
        }
        
        for(int i = 0; i < n; i++) {
            int sumeven = preeven + oddsum - preodd;
            int sumodd = preodd + evensum - preeven;

            if(i & 1) {
                sumeven -= nums[i];
                preodd += nums[i];
            } else {
                sumodd -= nums[i];
                preeven += nums[i];
            }
            
            if(sumodd == sumeven) ans++;
        }

        return ans;
    }
};
