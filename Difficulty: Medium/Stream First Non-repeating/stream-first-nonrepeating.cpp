class Solution {
  public:
    string firstNonRepeating(string &s) {
        queue<char>q;
        unordered_map<int,int>mp;
        string ans="";
        
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
            if(mp[s[i]-'a']==1)q.push(s[i]);
            while(!q.empty()&&mp[q.front()-'a']!=1){
                q.pop();
            }
            if(q.empty()){
                ans+='#';
            }
            else ans+=q.front();
        }
        return ans;
    }
};