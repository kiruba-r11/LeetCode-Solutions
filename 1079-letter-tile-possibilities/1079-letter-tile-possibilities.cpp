class Solution {
public:
    map <string , int> hash;
    void solve(string &tiles , string &cur) {
        
        for(int i = 0; i < tiles.size(); i++) {
            if(tiles[i] != '-') {
                char temp = tiles[i];
                tiles[i] = '-';
                cur.push_back(temp);
                
                solve(tiles , cur);
                hash[cur]++;
                
                cur.pop_back();
                tiles[i] = temp;
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        string cur = "";
        solve(tiles , cur);
        return hash.size();
    }
};