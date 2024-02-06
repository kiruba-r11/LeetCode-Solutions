class Solution {
public:
    int maxpoints = 0;
    void points(vector <int> &bob , vector <int> &alice , int bobscore , int alicescore , int arrow , int numarrow , vector <int> &ans) {
        
        if(arrow == -1) {
            if(bobscore > maxpoints) {
                if(numarrow > 0) bob[0] += numarrow;
                maxpoints = bobscore;
                ans = bob;
                if(numarrow > 0) bob[0] -= numarrow;
            }
            return ;
        }
        
        int alicearrow = alice[arrow];
        
        if(numarrow >= alicearrow + 1) {
            bob[arrow] = alicearrow + 1;
            numarrow -= alicearrow + 1;
            int curscore = bob[arrow] == 0 ? 0 : arrow;
            points(bob , alice , bobscore + curscore , alicescore , arrow - 1 , numarrow , ans);
            
            bob[arrow] = 0;
            numarrow += alicearrow + 1;
        }
        
        int curscore = alicearrow == 0 ? 0 : arrow;
        points(bob , alice , bobscore , alicescore + curscore , arrow - 1 , numarrow , ans);
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector <int> bob(12);
        vector <int> ans(12);
        points(bob , aliceArrows , 0 , 0 , 11 , numArrows , ans);
        return ans;
    }
};