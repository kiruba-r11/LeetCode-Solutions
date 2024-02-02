class Solution {
public:
    set <string> s;
    void numTile(string &tiles , string &cur , int n) {
        if(n == 0) {
            if(cur.size()) s.insert(cur);
            return;
        }
        
        for(int i = 0; i < tiles.size(); i++) {
            if(tiles[i] != '-') {
                char temp = tiles[i];
                tiles[i] = '-';
                
                // exclude
                numTile(tiles , cur , n - 1);
                
                // make effort
                cur.push_back(temp);
                
                // include
                numTile(tiles , cur , n - 1);
                
                // undo effort
                tiles[i] = temp;
                cur.pop_back();
            }
        }
        
    }
    int numTilePossibilities(string tiles) {
        string cur = "";
        int n = tiles.size();
        numTile(tiles , cur , n);
        return s.size();
    }
};
