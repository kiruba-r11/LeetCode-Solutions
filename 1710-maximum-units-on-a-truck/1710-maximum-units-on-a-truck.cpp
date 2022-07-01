class Solution {
public:
    
    static bool cmp(vector <int> &a , vector <int> &b) {
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
            
        sort(boxTypes.begin() , boxTypes.end() , cmp);
        int boxes = 0;
        for(auto box : boxTypes) {
            if (truckSize >= box[0]) {
                boxes += box[0] * box[1];
                truckSize -= box[0];
            }else {
                boxes += truckSize * box[1];
                return boxes;
            }
        }
        return boxes;
    }
};
