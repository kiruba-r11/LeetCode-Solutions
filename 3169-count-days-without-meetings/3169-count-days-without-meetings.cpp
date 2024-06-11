class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        stack <pair <int , int>> s;
        sort(meetings.begin() , meetings.end());
        
        int n = meetings.size();
        for(int i = 0; i < n; i++) {
            if(s.empty()) s.push({meetings[i][0] , meetings[i][1]});
            else {
                pair <int , int> in = s.top();
                s.pop();
                
                int start = in.first;
                int end = in.second;
                
                if(end >= meetings[i][0]) {
                    s.push({start , max(end , meetings[i][1])});
                } else {
                    s.push({start , end});
                    s.push({meetings[i][0] , meetings[i][1]});
                }
            }
        }
        
        int last = days;
        bool check = true;
        int ans = 0;
        while(!s.empty()) {
            pair <int , int> in = s.top();
            s.pop();
            
            int start = in.first;
            int end = in.second;
            
            ans += last - end - 1;
            if(last == days && check) {
                ans++;
                check = false;
            }
            last = start;
            
            if(s.empty()) {
                ans += start - 1;
            }
        }
        
        return ans;
     }
};