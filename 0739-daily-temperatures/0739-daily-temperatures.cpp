class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector <int> ngr(n);
        stack <pair <int , int>> s;
        
        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && s.top().first <= temp[i]) s.pop();
            if(!s.empty()) ngr[i] = s.top().second - i;
            s.push({temp[i] , i});
        }
        
        return ngr;
    }
};