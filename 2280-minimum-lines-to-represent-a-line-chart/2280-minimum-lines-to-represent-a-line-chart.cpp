class Solution {
public:
    int minimumLines(vector<vector<int>>& nums) {
        int n = nums.size();
        
        if(n <= 2) return n - 1;
        
        sort(nums.begin() , nums.end());
        long double slope = (long double)((long long)nums[1][1] - (long long)nums[0][1]) / (long double)((long long)nums[1][0] - (long long)nums[0][0]);
        
        // cout << nums[0][0] << " " << nums[0][1] << " , ";
        // cout << nums[1][0] << " " << nums[1][1] << " - " << slope << endl;
        
        int ans = 1;
        for(int i = 2; i < n; i++) {
            long double newSlope = 
                (long double)((long long)nums[i][1] - (long long)nums[i - 1][1]) / (long double)((long long)nums[i][0] - (long long)nums[i - 1][0]);
            // cout << nums[i - 1][0] << " " << nums[i - 1][1] << " , ";
            // cout << nums[i][0] << " " << nums[i][1] << " - " << newSlope << endl;
            if(newSlope != slope) {
                ans++;
                slope = newSlope;
            }
        }
        
        return ans;
    }
};

/*

[[1,7],[2,6],[3,5],[4,4],[5,4],[6,3],[7,2],[8,1]]
[[3,4],[1,2],[7,8],[2,3]]
[[36,9],[17,93],[34,4],[30,11],[11,41],[53,36],[5,92],[81,92],[28,36],[3,45],[72,33],[64,1],[4,70],[16,73],[99,20],[49,33],[47,74],[83,91]] 
[[9,35],[12,47],[68,90],[64,71],[33,99],[90,25],[42,91],[41,5],[28,12],[66,30],[78,10],[92,23],[88,45],[89,32],[3,74],[93,3],[44,15],[43,11],[91,41]]
[[83,35],[79,51],[61,48],[54,87],[44,93],[22,5],[87,28],[64,8],[89,78],[62,83],[58,72],[48,7],[97,16],[27,100],[65,48],[11,31],[29,76],[93,29],[72,59],[73,74],[9,90],[66,81],[12,8],[86,80],[84,43],[36,63],[80,45],[81,88],[95,5],[40,59]]

*/