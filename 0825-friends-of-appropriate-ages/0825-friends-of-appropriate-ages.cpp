class Solution {
public:
    int requests(vector <int> &ages , int age , int low , int high) {
        int ans = ages.size();
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(ages[mid] > age) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
    
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size();
        sort(ages.begin() , ages.end());
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int j = i;
            while(j < n && ages[i] == ages[j]) {
                j++;
            }
            int cnt = j - i;
            i = j - 1;
            int idx = requests(ages , 0.5 * ages[i] + 7 , 0 , i - 1);
            if(idx < i) ans += (i - idx) * cnt;
        }
        return ans;
    }
};