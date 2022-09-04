class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        int n = s.size();
        vector <int> hash(26 , -1);
        for(int i = 0; i < n; i++) {
            if(hash[s[i] - 'a'] != -1) {
                int dist = i - hash[s[i] - 'a'] - 1;
                if(distance[s[i] - 'a'] != dist) return false;
            } else {
                hash[s[i] - 'a'] = i;
            }
        }
        
        return true;
    }
};