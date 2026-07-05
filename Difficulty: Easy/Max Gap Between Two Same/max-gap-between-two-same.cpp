class Solution {
  public:
    int maxCharGap(string &s) {
        unordered_map<char, vector<int>> mp;
        
        int n = s.length(), res = -1;
        
        for (int i = 0; i < n; i++) {
            mp[s[i]].push_back(i);
        }
        
        for (auto i :mp) {
            if (i.second.size() > 1) {
                res = max(res, i.second.back() - i.second[0] - 1);
            }
        }
        
        return res;
    }
};