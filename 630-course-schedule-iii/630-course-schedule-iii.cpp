class Solution {
public:
    // map <int , int> dp[10005];
    int solve(vector <vector <int>> &nums , int day , int index , map <int , int> dp[]) {
    
        if(index == nums.size()) return 0;
        
        if(dp[index].find(day) != dp[index].end()) return dp[index][day];
        
        int time = day + nums[index][0];
        int pick = 0 , notpick = 0;
        
        if(time <= nums[index][1])
            pick = 1 + solve(nums , time , index + 1 , dp);
        
        notpick = solve(nums , day , index + 1 , dp);
        
        return dp[index][day] = max(pick , notpick);
    }
    
    static bool cmp(vector <int> &a , vector <int> &b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        vector <vector <int>> nums;
        for(auto i: courses) {
            if(i[0] <= i[1]) nums.push_back({i[0] , i[1]});
        }
        
        int n = nums.size();
        int day = 0 , index = 0;
        
        // vector <unordered_map <int , int>> dp(n);
        // map <int , int> dp[10005];
        sort(nums.begin() , nums.end() , cmp);
        priority_queue <int> pq;
        int cnt = 0 , ans = 0;
        
        for(int i = 0; i < n; i++) {
            cnt += nums[i][0];
            pq.push(nums[i][0]);
            if(cnt > nums[i][1]) {
                cnt -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
        // return solve(nums , day , index , dp);
    }
};