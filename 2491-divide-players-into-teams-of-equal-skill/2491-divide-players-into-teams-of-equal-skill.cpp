class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin() , skill.end());
        
        int n = skill.size();
        int i = 0 , j = n - 1;
        
        long long ans = 0;
        long long target = skill[0] + skill[n - 1];
        
        while(i < j) {
            long long sum = skill[i] + skill[j];
            if(sum == target) {
                ans += skill[i] * 1LL * skill[j];
            } else {
                return -1;
            }
            i++;
            j--;
        }
        
        return ans;
    }
};