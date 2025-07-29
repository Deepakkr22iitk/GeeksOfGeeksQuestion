class Solution {
  public:
    vector<int> asciirange(string& s) {
        vector<pair<int, int>> lst(26, {-1, 0});
        vector<int> res(26, 0);
        int curr = 0;
        
        for(int i=0; i<s.size(); ++i){
            if(lst[s[i]-'a'].first >= 0){
                res[s[i]-'a'] = curr - lst[s[i]-'a'].second;
            }
            else lst[s[i]-'a'] = {i, curr+s[i]};
            curr += s[i];
        }
        
        vector<int> ans;
        for(int i:res){
            if(i>0) ans.emplace_back(i);
        }
        
        return ans;
    }
};