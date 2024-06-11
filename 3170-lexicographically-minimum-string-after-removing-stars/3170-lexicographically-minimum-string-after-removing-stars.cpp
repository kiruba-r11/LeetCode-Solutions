class comp {
    public:
        bool operator() (pair <int , int> &a , pair <int , int> &b) {
            if(a.first > b.first) {
                return true;
            }
            else if(a.first == b.first && a.second < b.second) {
                return true;
            }

            return false;
        }
};

class Solution {
public:
    static bool cmp(pair <int , int> &a , pair <int , int> &b) {
    
        if(a.second <= b.second) return true;
        return false;
    }
    
    string clearStars(string s) {
        priority_queue <pair <int , int> , vector <pair <int , int>> , comp> pq;
        
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] != '*') {
                pq.push({s[i] , i});
            } else {
                pq.pop();
            }
        }
        
        vector <pair <int , int>> vp;
        while(!pq.empty()) {
            vp.push_back({pq.top().first , pq.top().second});
            pq.pop();
        }
        
        sort(vp.begin() , vp.end() , cmp);
        string ans = "";
        for(int i = 0; i < vp.size(); i++) {
            ans.push_back(vp[i].first);
        }
        
        return ans;
    }
};