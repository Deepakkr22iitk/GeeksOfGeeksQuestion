class Solution {
  public:
    int minParentheses(string& s) {
        string p;
        for(int i = 0;i<s.size();i++){
            if(!p.empty() && s[i]==')' && p.back()=='(') p
            .pop_back();
            else p.push_back(s[i]);
        }
        
        return p.size();
    }
};