class Solution {
  public:
    string chooseSwap(string &s) {
        vector<int> mp(26, -1);
        for(int i = 0;i<s.size(); i++){
            if(mp[s[i] - 'a'] == -1)mp[s[i] - 'a'] = i;
        }
        char c1, c2;
        c1 = c2 = '\0';
        for(int i = 0;i<s.size();i++){
            for(int j = 0;j<26;j++){
                if(('a' + j)>=s[i])break;
                if(mp[j] > i){
                    c1 = ('a' + j);
                    c2 = s[i];
                    goto end;
                }
            }
        }
        end:
        if(c1 == '\0' or c2 == '\0')return s;
        for(int i = 0;i<s.size();i++){
            if(s[i] == c1){
                s[i] = c2;
            }
            else if(s[i] == c2){
                s[i] = c1;
            }
        }
        return s;
    }
};
