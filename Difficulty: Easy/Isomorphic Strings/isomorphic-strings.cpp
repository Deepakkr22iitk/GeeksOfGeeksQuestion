class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        if(s1.length() != s2.length())return false;
        
        unordered_map<char , char>mp1;
        unordered_map<char , char>mp2;
        
        for(int i=0;i<s1.length();i++){
            mp1[s1[i]] = s2[i];
            mp2[s2[i]] = s1[i];
        }
        
        for(int i=0;i<s1.length();i++){
            if(mp1[s1[i]] != s2[i])return false;
            if(mp2[s2[i]] != s1[i])return false;
        }
        
        return true;
    }
};