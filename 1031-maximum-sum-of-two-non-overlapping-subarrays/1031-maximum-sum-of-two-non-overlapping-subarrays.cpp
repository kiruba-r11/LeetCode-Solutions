class Solution {
public:
    int slide(vector <int> &nums , int start , int end , int secondLen) {
        int i = start , j = start;
        int sum = 0;
        int ans = 0;
        
        while(j < end) {
            int window = j - i + 1;
            if(window <= secondLen) {
                sum += nums[j];
                if(window == secondLen) {
                    ans = max(ans , sum);
                }
                j++;
            } else {
                sum -= nums[i];
                i++;
            }
        }
        
        return ans;
    }
    
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        int i = 0 , j = 0;
        int sum = 0;
        int ans = 0;
        
        while(j < n) {
            int window = j - i + 1;
            if(window <= firstLen) {
                sum += nums[j];
                if(window == firstLen) {
                    int second = max(slide(nums , j + 1 , n , secondLen) , slide(nums , 0 , i - 1 , secondLen));
                    int first = sum;
                    ans = max(ans , first + second);
                }
                j++;
            } else {
                sum -= nums[i];
                i++;
            }
        }
        
        return ans;
    }
};