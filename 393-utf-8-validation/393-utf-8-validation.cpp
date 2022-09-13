class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for(int i = 0; i < n; i++) {
            vector <int> store(8);
            int elem = data[i];
            int j = 7;
            while(elem > 0) {
                store[j] = elem % 2;
                elem /= 2;
                j--;
            }
            
            int cnt = 0;
            j = 0;
            while(j < 7) {
                if(store[j] == 1) {
                    cnt++;
                } else {
                    break;
                }
                j++;
            }
            // cout << data[i] << " " << cnt << endl;
            if(cnt == 0) continue;
            else if(cnt == 1 || cnt >= 5) return false;
            else {
                if((n - i - 1) < (cnt - 1)) {
                    // cout << i << endl;
                    return false;
                }
                int k = i + 1;
                while(cnt > 1) {
                    if(((data[k] & (1 << 7)) != 0) && ((data[k] & (1 << 6)) == 0)) {
                        // cout << data[k] << " " << (data[k] & (1 << 7)) << endl;
                        k++;
                    }
                    else {
                        return false;
                    }
                    cnt--;
                }
                i = k - 1;
            }
        }
        return true;
    }
};