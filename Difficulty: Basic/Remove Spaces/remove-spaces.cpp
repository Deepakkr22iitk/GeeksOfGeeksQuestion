class Solution {
  public:
    string removeSpaces(string& s) {
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] != ' '){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};